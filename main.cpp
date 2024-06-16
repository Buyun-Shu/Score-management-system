//主函数
#include"student.h"
int main()														//主函数 
{
	int a; 
	STUDENT stu[500];											//结构体数组 
	STUDENT *point;												//结构体指针 											//结构体指针数组 
	point=stu;														 
										 
	printf("\n\n\n\n\n\n\t\t欢迎进入成绩管理系统!\n\n\n\t\t请按回车键开始 -----\n");	
	getchar();
	system("color F0");													
	for(;;)														
	{
		switch(menu_select())
		{
			case 1:
				initialize(point); 
				break;
			case 2:
				load(stu); 
				break;
			case 3:
				input_data(stu,grade);
				break; 
			case 4:
				a=editmenu();	 
				if(a==1)
					add_record(stu);
				else if(a==2)
					edit_record(stu);
				else if(a==3)
					delete_record(stu);
				break;
			case 5:
				search_student(stu);
				break;
			case 6:
				search_sex(stu); 
				break;
			case 7:
				search_clas(stu);
				break;
			case 8:
				search_grade(stu); 
				break;
			case 9:
				draw_chart(grade);
				break;
			case 10:
				 save(stu);
				 break;
			case 0:
				printf("感谢使用！\n");
				exit(0);										//退出系统		
			default:printf("选择错误！请重选");break; 
		} 
	}
return 0; 	 
} 
//定义菜单选择函数
int menu_select(void)

{	int menuitem=-1;										//初始化菜单选项 
	printf("\n\n\n");										//输出菜单界面 
	printf("\t|************学生成绩管理系统***********|\n");
	printf("\t|---------------------------------------|\n");
	printf("\t|\t\t主菜单项\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("\t|\t\t1---初始化  \t\t|\n");
	printf("\t|\t\t2---数据导入\t\t|\n");
	printf("\t|\t\t3---数据录入\t\t|\n");
	printf("\t|\t\t4---数据编辑\t\t|\n");
	printf("\t|\t\t5---查询学生\t\t|\n");
	printf("\t|\t\t6---查询性别\t\t|\n");
	printf("\t|\t\t7---查询班级\t\t|\n");
	printf("\t|\t\t8---查询年级\t\t|\n");
	printf("\t|\t\t9---图表绘制\t\t|\n");
	printf("\t|\t\t10--数据导出\t\t|\n");
	printf("\t|\t\t0---退出系统\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("		 东北大学-信息科学与工程学院     \n");
	printf("		自动化类2105班-C语言攻关小分队    \n");
	printf("\n\n"); 
	printf("	请键入菜单项数字选择相应的功能：");
	scanf("%d",&menuitem); 
	return(menuitem);		
} 

//定义初始化（清空）函数
void initialize(STUDENT *x)				
{
	int i,j;
	for(i=0;i<MaxNumber;i++,x++)
	{
		x->number=0;
		for(j=0;j<20&&x->name[j]!='\0';j++)
			x->name[j]='\0';
		x->sex=0;
		x->clas=0;
		for(j=0;j<10;j++)
			x->score[j]=0;
	}
	printf("\n\n\n\n\n\n\t#记录初始化已完成,请继续操作#\n"); 
} 
//定义数据录入函数 
void input_data(STUDENT stu[],int grade[][11])
{
	int i,j,k,count=1;
	printf("\n\t\t****************学生成绩数据录入界面****************\n\n");
	for(i=0;i<MaxNumber;i++)
	{	 
		printf("\nNO.%d\n********************",count); 
		printf("\n请输入学号（如果录入完成请键入-1）："); 
		scanf("%d",&stu[i].number);							//输入学号
		if(stu[i].number==-1)
		{
			MaxNumber=i;									//学号输入-1意味着结束 
			printf("\n\n\n\n#学生成绩数据录入完成,请继续操作#\n");			//定下学生人数 
			break;											//跳出所有循环 
		}
		printf("\n姓名：");
		scanf("%s",stu[i].name);							//输入姓名（字符串）不需要&
		printf("\n性别(1或0):");
		scanf("%d",&stu[i].sex);							//输入性别
		printf("\n班级：");
		scanf("%d",&stu[i].clas);							//输入班级 
		printf("\n各科成绩(第一次如果录入完成请键入-1）：");
		for(j=0;j<MaxCourse;j++)
			{
				scanf("%d",&stu[i].score[j]);				//输入各科成绩 
		    	if(stu[i].score[j]==-1)
		    	{
	    			MaxCourse=j;							//成绩输入-1意味着结束 
	    			continue;								//只是结束本次循环 
	    		}
	    		k=stu[i].score[j]/10;
	    		grade[j+1][k]++;
			}
		count++; 
	} 
} 
//定义数据编辑菜单
int editmenu()
{
	int edition=0;										//初始化菜单选项 
	printf("\n\n\n");										//输出菜单界面 
	printf("\t|************学生成绩管理系统***********|\n");
	printf("\t|---------------------------------------|\n");
	printf("\t|\t\t子菜单项\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("\t|\t\t1---追加记录 \t\t|\n");
	printf("\t|\t\t2---修改记录 \t\t|\n");
	printf("\t|\t\t3---删除记录 \t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("		  东北大学-信息科学与工程学院      \n");
	printf("		 自动化类2105班-C语言攻关小分队    \n");
	printf("\n");
	printf("	请键入菜单项数字选择相应的功能：");
	scanf("%d",&edition); 
	getchar(); 
	return(edition);
} 
//定义添加数据函数
void add_record(STUDENT stu[])
{
	int k,l,count=0;
	printf("\n\t\t****************数据添加界面****************\n\n");
	for(k=MaxNumber;k<500;k++)
	{
		printf("\n请输入学号（如果录入完成请键入-1）："); 
		scanf("%d",&stu[k].number);							//输入学号
		if(stu[k].number!=-1) count++;
		if(stu[k].number==-1)
		{
			MaxNumber+=count;									//学号输入-1意味着结束 
															//再次定下学生人数 
			break;											//跳出所有循环 
		}
		printf("\n请输入姓名：");
		scanf("%s",stu[k].name);							//输入姓名（字符串）不需要&
		printf("\n请输入性别（1或0):");
		scanf("%d",&stu[k].sex);							//输入性别
		printf("\n请输入班级：");
		scanf("%d",&stu[k].clas);							//输入班级 
		printf("\n请输入各科成绩：");
		for(l=0;l<MaxCourse;l++)
			{
				scanf("%d",&stu[k].score[l]);				//输入各科成绩 
			}
	} 
}
//定义删除函数
void delete_record(STUDENT *x) 
{
	int num=0;
	printf("\n请输入要删除学生的学号：");
	scanf("%d",&num); 
	for(int i=0;i<MaxNumber;i++,x++)
		{
			if(x->number==num)
			{
				
				x->number=0;
				for(int j=0;j<20&&x->name[j]!='\0';j++)
					x->name[j]='\0';
				x->sex=0;
				x->clas=0;
				for(int j=0;j<10;j++)
					x->score[j]=0;
				break;
			}
		}
	printf("\n该学生信息已经删除！"); 	
}
//定义修改数据函数
void edit_record(STUDENT stu[])
{
	int i,j,k=0,l=0,m;
	for(i=0;i<MaxNumber;i++)
	{
		printf("请输入要修改学生的学号：");
		scanf("%d",&k);
		if(stu[i].number==k)
		{
			printf("\n\t\t**********************学生档案**********************\t\t\n\n");
				printf("\t\t学号:%-10d姓名:%-10s性别:%-10d班级:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t各科成绩：\n\n");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("\t\t第%d科:%-9d",q+1,stu[i].score[q]);			
			}
			printf("\n请再次确定是否要修改数据.是请按1，否请按0：\n");
			scanf("%d",&j);
			if(j)
			{
				printf("要修改第几门课的成绩？\n");
				scanf("%d",&l);
				printf("成绩%d目前为：%d\n",l,stu[i].score[l-1]);
				printf("请输入修改后的成绩：");
				scanf("%d",&stu[i].score[l-1]);
				printf("\n\n记录修改成功！");
				break;
			}
			else if(0)
			continue;
		}
		else 
			continue;
	} 
}
//定义查询学生信息函数 
void search_student(STUDENT stu[])
{
	printf("\n\t\t**********************学生成绩查询界面**********************\t\t\n\n");
	int i,j,input;
	printf("\n\t\t使用学号查询请按1,使用姓名查询请按2：");
	scanf("%d",&input);
	getchar();
	if(input==1)
	{
		printf("\n\t\t请输入学号：");
		scanf("%d",&j);
		for(i=0;i<MaxNumber;i++)
		{
			if(stu[i].number==j)
			{
				printf("\n\t\t**********************学生档案**********************\t\t\n\n");
				printf("\t\t学号:%-10d姓名:%-10s性别:%-10d班级:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t各科成绩：\n\n\t\t");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("第%d科:%-9d",q+1,stu[i].score[q]);
				}
			}
			
	 	} 
	}
	else
	{
		char name2[20]; 
		printf("\n\t\t请输入姓名：");
		gets(name2);
		for(i=0;i<MaxNumber;i++)
		{
			if(strcmp(name2,stu[i].name)==0)
			{
				printf("\n\t\t**********************学生档案**********************\t\t\n\n");
				printf("\t\t学号:%-10d姓名:%-10s性别:%-10d班级:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t各科成绩：\n\n");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("第%d科:%-9d",q+1,stu[i].score[q]);
				}
			}
		}
	}	
}
//定义查询班级信息函数
void search_clas(STUDENT stu[])
{
	printf("\n\t\t**********************班级成绩查询界面**********************\t\t\n\n");
	int n,i,j,count=0;
	int aver,sum;
	
	printf("\t请输入所查询的班级序号：");
	scanf("%d",&n);

	for(sum=0,i=0;i<MaxNumber;i++)
	{
	  if(stu[i].clas==n)
	    for(j=0;j<MaxCourse;j++)
	      sum+=stu[i].score[j]; 	
	}
	printf("\n\t\t\t************%d班成绩信息************\n",n);
    printf("\n\t\t\t总成绩：%d\n\n",sum);
	
	int max,min;
    int p;

	for(i=0;i<MaxNumber;i++)
	{
		if (stu[i].clas==n)
		max=stu[i].score[0];
		p=i;
		break;	
	}//找到起始值，设其为第一代最大值 
	for(i=p;i<MaxNumber;i++)
	{
		if(stu[i].clas==n)
		{
			for(j=0;j<MaxCourse;j++)
			  if(stu[i].score[j]>max)
			  max=stu[i].score[j]; 
		}
	}
	printf("\n\t\t\t该班最高成绩为%d分\t",max);
  
	
	for(i=0;i<MaxNumber;i++)
	{
		if (stu[i].clas==n)
		min=stu[i].score[0];
		p=i;
		break;
	}//找到起始值，设其为第一代最小值 
	for(i=p;i<MaxNumber;i++)
	{
		if(stu[i].clas==n)
		{
			for(j=0;j<MaxCourse;j++)
			  if(stu[i].score[j]<min)
			  min=stu[i].score[j]; 
		}
	}
	printf("最低成绩是%d\n\n\n",min);

    for(j=0;j<MaxCourse;j++)
	  {
		for(sum=0,count=0,i=0;i<MaxNumber;i++)
		  	{
		    if(stu[i].clas==n)
		      {
			   	sum+=stu[i].score[j];
			   	count++;
			  }
			}  
		aver=sum/count;
		printf("\t\t\t第%d科的总成绩为：%d\t",j+1,sum); 	
	    printf("平均成绩：%d\n\n",aver);		  		      
      } 
    printf("\n");
}
	
void search_grade(STUDENT stu[])
{
	printf("\n\t\t**********************年级信息查询界面**********************\t\t\n\n");
	
	int n,i,j,temp;
	
	for(n=0;n<MaxCourse;n++)
	  {
	    
		int a[MaxNumber]; 
		for(i=0;i<MaxNumber;i++)
	      {
		    a[i]=stu[i].score[n];
	      }//把该科成绩放到另一个相同大小的数组中。 
		
		for(j=0;j<MaxNumber-1;j++)
	      for(i=0;i<MaxNumber-1-j;i++)
	        {
	    	  if(a[i+1]>a[i])
			    {
			      temp=a[i];a[i]=a[i+1];a[i+1]=temp;
			    }	 
	        } //使用起泡法排序	
	    
		printf("\t\t第%d科成绩前五为:\t%d\t%d\t%d\t%d\t%d\n\n",n+1,a[0],a[1],a[2],a[3],a[4]);	
	  }
	
	    int sum,b[MaxNumber];
	    
		for(i=0;i<MaxNumber;i++)
	      {
		    for(sum=0,n=0;n<MaxCourse;n++) sum+=stu[i].score[n];
	        b[i]=sum;
		  }//把每个学生成绩放到另一个相同大小的数组中
	    
		for(j=0;j<MaxNumber-1;j++)
	    {  
		  	for(i=0;i<MaxNumber-1-j;i++)
	        {
	    	  	if(b[i+1]>b[i])
			    {
			      	temp=b[i];b[i]=b[i+1];b[i+1]=temp;
			    }	 
	        } 	//使用起泡法排序			
	  	}
	printf("\n\t\t年级总成绩前五为:\t%d\t%d\t%d\t%d\t%d\n\n",b[0],b[1],b[2],b[3],b[4]);
 }   
	
//定义查询性别信息函数
void search_sex(STUDENT stu[])
{
    printf("\n\t\t**********************性别信息查询界面**********************\t\t\n\n");
	int i,j,k,l,m,n; 
 	int boy=0;
    int girl=0;
    float sum_boy=0;
    float sum_girl=0;
    float aver_boy,aver_girl;
    printf("\t\t查询男同学成绩请键入1，查询女同学成绩请键入0：");
    scanf("%d",&m);
    if(m)
    {
    	printf("\n\t\t请键入所查询的班级号：");
		scanf("%d",&n); 
    	for(i=0;i<MaxNumber;i++)
    	{
    		if(stu[i].clas==n&&stu[i].sex==1)
    	 	{
				 	boy++;
	    	for(j=0;j<MaxCourse;j++)
				sum_boy+=stu[i].score[j];
			}	
	    }
    printf("\n\n\t\t\t%d班男生总成绩为：%d\t",n,(int)sum_boy);
    aver_boy=sum_boy/boy;
	printf("平均成绩为：%5.2f\n",aver_boy);
	}
	else if(!m)
	{
		n=0;
		printf("请键入所查询的班级号：");
		scanf("%d",&n);
		for(i=0;i<MaxNumber;i++)
		{
    		if(stu[i].clas==n&&stu[i].sex==0)
    	 	{
				 	girl++;
	    	for(j=0;j<MaxCourse;j++)
				sum_girl+=stu[i].score[j];
			}	
	    }
    printf("\n\n\t\t\t%d班女生总成绩为%d\n",n,(int)sum_girl);
    aver_girl=sum_girl/girl;
	printf("%d班女生平均成绩为%5.2f\n",n,aver_girl);
	}
}
//定义绘制模拟直方图函数
void draw_chart(int grade[10][11])						//grade记录的是各分数段的人数 
{
	int i,j,max,k,n,x,temp;
	char screen[22][44];
	printf("请键入所查询的科目号：");
	scanf("%d",&n);
	printf("\n模拟直方图\n");
	max=0;
	for(i=1;i<=10;i++)								//寻找分数段中人数最多的 
		if(grade[n][i]>max)
			max=grade[n][i];
	for(i=1;i<=10;i++)
		grade[n][i]=(int)(20.0*grade[n][i]/max+0.5);		//计算输出星号数
	for(i=0;i<22;i++)
		for(j=0;j<44;j++)
			screen[i][j]=0;						//先将输出的所有点清零
	for(i=0;i<42;i++)
		screen[21][i]='-';							//绘制x轴 
	screen[21][42]='X';	
	screen[0][0]='Y';
	for(i=1;i<22;i++)
		screen[i][0]='|';							//绘制y轴
	k=1;
	for(x=1;x<=10;x++,k+=4)
	{
		temp=grade[n][x];
		if(temp)
			for(i=1;i<=temp;i++)
				for(j=1;j<=4;j++)
					screen[20-i+1][j+k+2]='*';
	}
	for(i=0;i<22;i++)
	{
		for(j=0;j<44;j++)
		{
			if(screen[i][j]!=0)
				printf("%c",screen[i][j]);
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("\n");
	printf("0  10  20  30  40  50  60  70  80  90  100\n");		
	getchar();		 
}
//定义创建用户函数
void CreatUser() 
{
	user *pointer,*New;
	pointer=UsHead;
	while(pointer->next)
		pointer=pointer->next;
	New=(user*)malloc(sizeof(user));
	New->next=NULL;
	printf("请输入用户名：");
	fflush(stdin);										//清空文件缓冲区
	gets(New->name);
	printf("请输入密码：");
	fflush(stdin);	
	gets(New->password);
	pointer->next=New;
	printf("创建成功！");					 
}
//定义删除用户函数
user *DeletUser(user *acuser)
{
	user *pointer;
	pointer=UsHead;
	if(!acuser)
	{
		MessageBox(NULL,_T("无用户！"),_T("提示窗口"),MB_ICONWARNING);
		return NULL;
	}
	while(pointer->next!=acuser)
		pointer=pointer->next;
	pointer->next=acuser->next;
	free(acuser);
	printf("删除成功！");
	return NULL;	
} 
//定义更改用户密码函数
void UpdatePassword(user *acuser)
{
	if(!acuser)
	{
		MessageBox(NULL,_T("无用户！"),_T("提示窗口"),MB_ICONWARNING);
		return;	
	}	
	printf("请输入密码：");
	fflush(stdin); 
	gets(acuser->password);
	printf("更改密码成功！"); 
} 
//定义登录界面函数
user *log_in()
{
	char name[20];
	char password[10];
	user *pointer;
	system("color F0");
	pointer=UsHead->next;
	if(!pointer)
		return NULL;
	while(1)
	{
		system("cls");
		pointer=UsHead->next;
		printf("\n\n\t\t\t请输入用户名：");
		fflush(stdin);
		gets(name);
		printf("\t\t\t请输入密码："); 
		fflush(stdin);
		gets(password);
		while(pointer)
		{
			if(!strcmp(name,pointer->name)&&!strcmp(password,pointer->password))
			{
				MessageBox(NULL,_T("登录成功！"),_T("提示窗口"),MB_ICONWARNING);
				Sleep(500);
				break;
			}
			pointer=pointer->next;
		}
		if(pointer&&!strcmp(name,pointer->name)&&!strcmp(password,pointer->password))
			break;
		else
			MessageBox(NULL,_T("密码错误！"),_T("提示窗口"),MB_ICONWARNING);
			putchar('\n'); 
	}
	return pointer;
} 
//定义数据导出（保存到磁盘文件）函数
void save(STUDENT stu[])
{
	FILE *fp;
	int i;
	if((fp=fopen("student++.dat","wb"))==NULL)
		{
			printf("cannot open file\n");
			return;
		}
	for(i=0;i<MaxNumber;i++)
		if(fwrite(&stu[i],sizeof(STUDENT),1,fp)!=1)
			printf("file write error\n");
	fclose(fp);	
	printf("数据已经转存到磁盘文件student.dat中！"); 
} 
//定义数据从文件导入函数
void load(STUDENT stu[])
{
	FILE *fp;
	int i;
	if((fp=fopen("student.dat","rb"))==NULL)
	{
		printf("cannot open infile\n");
		return;
	}
	for(i=0;i<MaxNumber;i++)
		if(fread(&stu[i],sizeof(STUDENT),1,fp)!=1)
		{
			if(feof(fp));
			{
				fclose(fp);
				printf("数据导入成功！\n");
				return;
			}
			printf("file read error\n");		
		}
	fclose(fp);
} 


