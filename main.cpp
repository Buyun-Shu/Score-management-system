//������
#include"student.h"
int main()														//������ 
{
	int a; 
	STUDENT stu[500];											//�ṹ������ 
	STUDENT *point;												//�ṹ��ָ�� 											//�ṹ��ָ������ 
	point=stu;														 
										 
	printf("\n\n\n\n\n\n\t\t��ӭ����ɼ�����ϵͳ!\n\n\n\t\t�밴�س�����ʼ -----\n");	
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
				printf("��лʹ�ã�\n");
				exit(0);										//�˳�ϵͳ		
			default:printf("ѡ���������ѡ");break; 
		} 
	}
return 0; 	 
} 
//����˵�ѡ����
int menu_select(void)

{	int menuitem=-1;										//��ʼ���˵�ѡ�� 
	printf("\n\n\n");										//����˵����� 
	printf("\t|************ѧ���ɼ�����ϵͳ***********|\n");
	printf("\t|---------------------------------------|\n");
	printf("\t|\t\t���˵���\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("\t|\t\t1---��ʼ��  \t\t|\n");
	printf("\t|\t\t2---���ݵ���\t\t|\n");
	printf("\t|\t\t3---����¼��\t\t|\n");
	printf("\t|\t\t4---���ݱ༭\t\t|\n");
	printf("\t|\t\t5---��ѯѧ��\t\t|\n");
	printf("\t|\t\t6---��ѯ�Ա�\t\t|\n");
	printf("\t|\t\t7---��ѯ�༶\t\t|\n");
	printf("\t|\t\t8---��ѯ�꼶\t\t|\n");
	printf("\t|\t\t9---ͼ�����\t\t|\n");
	printf("\t|\t\t10--���ݵ���\t\t|\n");
	printf("\t|\t\t0---�˳�ϵͳ\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("		 ������ѧ-��Ϣ��ѧ�빤��ѧԺ     \n");
	printf("		�Զ�����2105��-C���Թ���С�ֶ�    \n");
	printf("\n\n"); 
	printf("	�����˵�������ѡ����Ӧ�Ĺ��ܣ�");
	scanf("%d",&menuitem); 
	return(menuitem);		
} 

//�����ʼ������գ�����
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
	printf("\n\n\n\n\n\n\t#��¼��ʼ�������,���������#\n"); 
} 
//��������¼�뺯�� 
void input_data(STUDENT stu[],int grade[][11])
{
	int i,j,k,count=1;
	printf("\n\t\t****************ѧ���ɼ�����¼�����****************\n\n");
	for(i=0;i<MaxNumber;i++)
	{	 
		printf("\nNO.%d\n********************",count); 
		printf("\n������ѧ�ţ����¼����������-1����"); 
		scanf("%d",&stu[i].number);							//����ѧ��
		if(stu[i].number==-1)
		{
			MaxNumber=i;									//ѧ������-1��ζ�Ž��� 
			printf("\n\n\n\n#ѧ���ɼ�����¼�����,���������#\n");			//����ѧ������ 
			break;											//��������ѭ�� 
		}
		printf("\n������");
		scanf("%s",stu[i].name);							//�����������ַ���������Ҫ&
		printf("\n�Ա�(1��0):");
		scanf("%d",&stu[i].sex);							//�����Ա�
		printf("\n�༶��");
		scanf("%d",&stu[i].clas);							//����༶ 
		printf("\n���Ƴɼ�(��һ�����¼����������-1����");
		for(j=0;j<MaxCourse;j++)
			{
				scanf("%d",&stu[i].score[j]);				//������Ƴɼ� 
		    	if(stu[i].score[j]==-1)
		    	{
	    			MaxCourse=j;							//�ɼ�����-1��ζ�Ž��� 
	    			continue;								//ֻ�ǽ�������ѭ�� 
	    		}
	    		k=stu[i].score[j]/10;
	    		grade[j+1][k]++;
			}
		count++; 
	} 
} 
//�������ݱ༭�˵�
int editmenu()
{
	int edition=0;										//��ʼ���˵�ѡ�� 
	printf("\n\n\n");										//����˵����� 
	printf("\t|************ѧ���ɼ�����ϵͳ***********|\n");
	printf("\t|---------------------------------------|\n");
	printf("\t|\t\t�Ӳ˵���\t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("\t|\t\t1---׷�Ӽ�¼ \t\t|\n");
	printf("\t|\t\t2---�޸ļ�¼ \t\t|\n");
	printf("\t|\t\t3---ɾ����¼ \t\t|\n");
	printf("\t|---------------------------------------|\n"); 
	printf("		  ������ѧ-��Ϣ��ѧ�빤��ѧԺ      \n");
	printf("		 �Զ�����2105��-C���Թ���С�ֶ�    \n");
	printf("\n");
	printf("	�����˵�������ѡ����Ӧ�Ĺ��ܣ�");
	scanf("%d",&edition); 
	getchar(); 
	return(edition);
} 
//����������ݺ���
void add_record(STUDENT stu[])
{
	int k,l,count=0;
	printf("\n\t\t****************������ӽ���****************\n\n");
	for(k=MaxNumber;k<500;k++)
	{
		printf("\n������ѧ�ţ����¼����������-1����"); 
		scanf("%d",&stu[k].number);							//����ѧ��
		if(stu[k].number!=-1) count++;
		if(stu[k].number==-1)
		{
			MaxNumber+=count;									//ѧ������-1��ζ�Ž��� 
															//�ٴζ���ѧ������ 
			break;											//��������ѭ�� 
		}
		printf("\n������������");
		scanf("%s",stu[k].name);							//�����������ַ���������Ҫ&
		printf("\n�������Ա�1��0):");
		scanf("%d",&stu[k].sex);							//�����Ա�
		printf("\n������༶��");
		scanf("%d",&stu[k].clas);							//����༶ 
		printf("\n��������Ƴɼ���");
		for(l=0;l<MaxCourse;l++)
			{
				scanf("%d",&stu[k].score[l]);				//������Ƴɼ� 
			}
	} 
}
//����ɾ������
void delete_record(STUDENT *x) 
{
	int num=0;
	printf("\n������Ҫɾ��ѧ����ѧ�ţ�");
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
	printf("\n��ѧ����Ϣ�Ѿ�ɾ����"); 	
}
//�����޸����ݺ���
void edit_record(STUDENT stu[])
{
	int i,j,k=0,l=0,m;
	for(i=0;i<MaxNumber;i++)
	{
		printf("������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%d",&k);
		if(stu[i].number==k)
		{
			printf("\n\t\t**********************ѧ������**********************\t\t\n\n");
				printf("\t\tѧ��:%-10d����:%-10s�Ա�:%-10d�༶:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t���Ƴɼ���\n\n");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("\t\t��%d��:%-9d",q+1,stu[i].score[q]);			
			}
			printf("\n���ٴ�ȷ���Ƿ�Ҫ�޸�����.���밴1�����밴0��\n");
			scanf("%d",&j);
			if(j)
			{
				printf("Ҫ�޸ĵڼ��ſεĳɼ���\n");
				scanf("%d",&l);
				printf("�ɼ�%dĿǰΪ��%d\n",l,stu[i].score[l-1]);
				printf("�������޸ĺ�ĳɼ���");
				scanf("%d",&stu[i].score[l-1]);
				printf("\n\n��¼�޸ĳɹ���");
				break;
			}
			else if(0)
			continue;
		}
		else 
			continue;
	} 
}
//�����ѯѧ����Ϣ���� 
void search_student(STUDENT stu[])
{
	printf("\n\t\t**********************ѧ���ɼ���ѯ����**********************\t\t\n\n");
	int i,j,input;
	printf("\n\t\tʹ��ѧ�Ų�ѯ�밴1,ʹ��������ѯ�밴2��");
	scanf("%d",&input);
	getchar();
	if(input==1)
	{
		printf("\n\t\t������ѧ�ţ�");
		scanf("%d",&j);
		for(i=0;i<MaxNumber;i++)
		{
			if(stu[i].number==j)
			{
				printf("\n\t\t**********************ѧ������**********************\t\t\n\n");
				printf("\t\tѧ��:%-10d����:%-10s�Ա�:%-10d�༶:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t���Ƴɼ���\n\n\t\t");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("��%d��:%-9d",q+1,stu[i].score[q]);
				}
			}
			
	 	} 
	}
	else
	{
		char name2[20]; 
		printf("\n\t\t������������");
		gets(name2);
		for(i=0;i<MaxNumber;i++)
		{
			if(strcmp(name2,stu[i].name)==0)
			{
				printf("\n\t\t**********************ѧ������**********************\t\t\n\n");
				printf("\t\tѧ��:%-10d����:%-10s�Ա�:%-10d�༶:%-10d",stu[i].number,stu[i].name,stu[i].sex,stu[i].clas);
				printf("\n\n\t\t���Ƴɼ���\n\n");
				for(int q=0;q<MaxCourse;q++)
				{
					if(stu[i].score[q]==0)
					break;
					printf("��%d��:%-9d",q+1,stu[i].score[q]);
				}
			}
		}
	}	
}
//�����ѯ�༶��Ϣ����
void search_clas(STUDENT stu[])
{
	printf("\n\t\t**********************�༶�ɼ���ѯ����**********************\t\t\n\n");
	int n,i,j,count=0;
	int aver,sum;
	
	printf("\t����������ѯ�İ༶��ţ�");
	scanf("%d",&n);

	for(sum=0,i=0;i<MaxNumber;i++)
	{
	  if(stu[i].clas==n)
	    for(j=0;j<MaxCourse;j++)
	      sum+=stu[i].score[j]; 	
	}
	printf("\n\t\t\t************%d��ɼ���Ϣ************\n",n);
    printf("\n\t\t\t�ܳɼ���%d\n\n",sum);
	
	int max,min;
    int p;

	for(i=0;i<MaxNumber;i++)
	{
		if (stu[i].clas==n)
		max=stu[i].score[0];
		p=i;
		break;	
	}//�ҵ���ʼֵ������Ϊ��һ�����ֵ 
	for(i=p;i<MaxNumber;i++)
	{
		if(stu[i].clas==n)
		{
			for(j=0;j<MaxCourse;j++)
			  if(stu[i].score[j]>max)
			  max=stu[i].score[j]; 
		}
	}
	printf("\n\t\t\t�ð���߳ɼ�Ϊ%d��\t",max);
  
	
	for(i=0;i<MaxNumber;i++)
	{
		if (stu[i].clas==n)
		min=stu[i].score[0];
		p=i;
		break;
	}//�ҵ���ʼֵ������Ϊ��һ����Сֵ 
	for(i=p;i<MaxNumber;i++)
	{
		if(stu[i].clas==n)
		{
			for(j=0;j<MaxCourse;j++)
			  if(stu[i].score[j]<min)
			  min=stu[i].score[j]; 
		}
	}
	printf("��ͳɼ���%d\n\n\n",min);

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
		printf("\t\t\t��%d�Ƶ��ܳɼ�Ϊ��%d\t",j+1,sum); 	
	    printf("ƽ���ɼ���%d\n\n",aver);		  		      
      } 
    printf("\n");
}
	
void search_grade(STUDENT stu[])
{
	printf("\n\t\t**********************�꼶��Ϣ��ѯ����**********************\t\t\n\n");
	
	int n,i,j,temp;
	
	for(n=0;n<MaxCourse;n++)
	  {
	    
		int a[MaxNumber]; 
		for(i=0;i<MaxNumber;i++)
	      {
		    a[i]=stu[i].score[n];
	      }//�ѸÿƳɼ��ŵ���һ����ͬ��С�������С� 
		
		for(j=0;j<MaxNumber-1;j++)
	      for(i=0;i<MaxNumber-1-j;i++)
	        {
	    	  if(a[i+1]>a[i])
			    {
			      temp=a[i];a[i]=a[i+1];a[i+1]=temp;
			    }	 
	        } //ʹ�����ݷ�����	
	    
		printf("\t\t��%d�Ƴɼ�ǰ��Ϊ:\t%d\t%d\t%d\t%d\t%d\n\n",n+1,a[0],a[1],a[2],a[3],a[4]);	
	  }
	
	    int sum,b[MaxNumber];
	    
		for(i=0;i<MaxNumber;i++)
	      {
		    for(sum=0,n=0;n<MaxCourse;n++) sum+=stu[i].score[n];
	        b[i]=sum;
		  }//��ÿ��ѧ���ɼ��ŵ���һ����ͬ��С��������
	    
		for(j=0;j<MaxNumber-1;j++)
	    {  
		  	for(i=0;i<MaxNumber-1-j;i++)
	        {
	    	  	if(b[i+1]>b[i])
			    {
			      	temp=b[i];b[i]=b[i+1];b[i+1]=temp;
			    }	 
	        } 	//ʹ�����ݷ�����			
	  	}
	printf("\n\t\t�꼶�ܳɼ�ǰ��Ϊ:\t%d\t%d\t%d\t%d\t%d\n\n",b[0],b[1],b[2],b[3],b[4]);
 }   
	
//�����ѯ�Ա���Ϣ����
void search_sex(STUDENT stu[])
{
    printf("\n\t\t**********************�Ա���Ϣ��ѯ����**********************\t\t\n\n");
	int i,j,k,l,m,n; 
 	int boy=0;
    int girl=0;
    float sum_boy=0;
    float sum_girl=0;
    float aver_boy,aver_girl;
    printf("\t\t��ѯ��ͬѧ�ɼ������1����ѯŮͬѧ�ɼ������0��");
    scanf("%d",&m);
    if(m)
    {
    	printf("\n\t\t���������ѯ�İ༶�ţ�");
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
    printf("\n\n\t\t\t%d�������ܳɼ�Ϊ��%d\t",n,(int)sum_boy);
    aver_boy=sum_boy/boy;
	printf("ƽ���ɼ�Ϊ��%5.2f\n",aver_boy);
	}
	else if(!m)
	{
		n=0;
		printf("���������ѯ�İ༶�ţ�");
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
    printf("\n\n\t\t\t%d��Ů���ܳɼ�Ϊ%d\n",n,(int)sum_girl);
    aver_girl=sum_girl/girl;
	printf("%d��Ů��ƽ���ɼ�Ϊ%5.2f\n",n,aver_girl);
	}
}
//�������ģ��ֱ��ͼ����
void draw_chart(int grade[10][11])						//grade��¼���Ǹ������ε����� 
{
	int i,j,max,k,n,x,temp;
	char screen[22][44];
	printf("���������ѯ�Ŀ�Ŀ�ţ�");
	scanf("%d",&n);
	printf("\nģ��ֱ��ͼ\n");
	max=0;
	for(i=1;i<=10;i++)								//Ѱ�ҷ��������������� 
		if(grade[n][i]>max)
			max=grade[n][i];
	for(i=1;i<=10;i++)
		grade[n][i]=(int)(20.0*grade[n][i]/max+0.5);		//��������Ǻ���
	for(i=0;i<22;i++)
		for(j=0;j<44;j++)
			screen[i][j]=0;						//�Ƚ���������е�����
	for(i=0;i<42;i++)
		screen[21][i]='-';							//����x�� 
	screen[21][42]='X';	
	screen[0][0]='Y';
	for(i=1;i<22;i++)
		screen[i][0]='|';							//����y��
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
//���崴���û�����
void CreatUser() 
{
	user *pointer,*New;
	pointer=UsHead;
	while(pointer->next)
		pointer=pointer->next;
	New=(user*)malloc(sizeof(user));
	New->next=NULL;
	printf("�������û�����");
	fflush(stdin);										//����ļ�������
	gets(New->name);
	printf("���������룺");
	fflush(stdin);	
	gets(New->password);
	pointer->next=New;
	printf("�����ɹ���");					 
}
//����ɾ���û�����
user *DeletUser(user *acuser)
{
	user *pointer;
	pointer=UsHead;
	if(!acuser)
	{
		MessageBox(NULL,_T("���û���"),_T("��ʾ����"),MB_ICONWARNING);
		return NULL;
	}
	while(pointer->next!=acuser)
		pointer=pointer->next;
	pointer->next=acuser->next;
	free(acuser);
	printf("ɾ���ɹ���");
	return NULL;	
} 
//��������û����뺯��
void UpdatePassword(user *acuser)
{
	if(!acuser)
	{
		MessageBox(NULL,_T("���û���"),_T("��ʾ����"),MB_ICONWARNING);
		return;	
	}	
	printf("���������룺");
	fflush(stdin); 
	gets(acuser->password);
	printf("��������ɹ���"); 
} 
//�����¼���溯��
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
		printf("\n\n\t\t\t�������û�����");
		fflush(stdin);
		gets(name);
		printf("\t\t\t���������룺"); 
		fflush(stdin);
		gets(password);
		while(pointer)
		{
			if(!strcmp(name,pointer->name)&&!strcmp(password,pointer->password))
			{
				MessageBox(NULL,_T("��¼�ɹ���"),_T("��ʾ����"),MB_ICONWARNING);
				Sleep(500);
				break;
			}
			pointer=pointer->next;
		}
		if(pointer&&!strcmp(name,pointer->name)&&!strcmp(password,pointer->password))
			break;
		else
			MessageBox(NULL,_T("�������"),_T("��ʾ����"),MB_ICONWARNING);
			putchar('\n'); 
	}
	return pointer;
} 
//�������ݵ��������浽�����ļ�������
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
	printf("�����Ѿ�ת�浽�����ļ�student.dat�У�"); 
} 
//�������ݴ��ļ����뺯��
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
				printf("���ݵ���ɹ���\n");
				return;
			}
			printf("file read error\n");		
		}
	fclose(fp);
} 


