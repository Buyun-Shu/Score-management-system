//头文件名:student.h 
#include<stdio.h>										//输入输出函数库 
#include<stdlib.h>										//动态内存分配函数库
#include<Windows.h>										//引入windows下的GDI库进行绘图 
#include<string.h> 										//字符串处理函数库
#include<time.h>										//时间函数库
#include<conio.h>										//输入输出函数库 
#include<tchar.h>										//字符串宏库 
//定义学生结构体				 
typedef struct student									//声明新类型名
{
	int number;											//学号
	char name[20];										//姓名
	int sex;											//性别：男是1,女是0 
	int clas;											//班级 
	int score[10]; 										//科目成绩 
}STUDENT;
//定义用户管理结构体链表 
typedef struct User										//声明新类型名
{
	char name[20];										//用户名
	char password[10];									//密码
	struct User *next;									//指针指向下一个节点 
}user;
//函数声明在文件开头
int menu_select();										//菜单选择
int editmenu();											//数据编辑菜单 
void initialize(STUDENT *x);							//初始化
void input_data(STUDENT stu[],int grade[][11]);			//数据输入 
void add_record(STUDENT stu[]);							//添加学生信息 
void delete_record(STUDENT stu[]); 						//删除学生信息
void edit_record(STUDENT stu[]);						//修改学生信息 
void search_student(STUDENT stu[]);						//查询学生信息
void search_sex(STUDENT stu[]);							//查询性别信息 
void search_clas(STUDENT stu[]);						//查询班级信息 
void search_grade(STUDENT stu[]);						//查询年级信息 
void draw_chart(int grade[][11]);						//绘制模拟直方图 
void CreatUser();										//创建用户
user *DeletUser(user *acuser); 							//删除用户
void UpdatePassword(user *acuser);						//更改用户密码 
user *log_in();											//登录界面
void save(STUDENT stu[]);								//文件保存（数据导出）
void load(STUDENT stu[]);								//数据导入 
//定义全局变量 
int MaxNumber=500;										//全年级学生上限 
int MaxCourse=4;										//科目上限
int grade[10][11];										//每门课各个分数段 
user *UsHead;											//定义用户的头结点为全局变量
user *InitUser;											//初始化用户头结点 


