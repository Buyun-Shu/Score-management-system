//ͷ�ļ���:student.h 
#include<stdio.h>										//������������� 
#include<stdlib.h>										//��̬�ڴ���亯����
#include<Windows.h>										//����windows�µ�GDI����л�ͼ 
#include<string.h> 										//�ַ�����������
#include<time.h>										//ʱ�亯����
#include<conio.h>										//������������� 
#include<tchar.h>										//�ַ������ 
//����ѧ���ṹ��				 
typedef struct student									//������������
{
	int number;											//ѧ��
	char name[20];										//����
	int sex;											//�Ա�����1,Ů��0 
	int clas;											//�༶ 
	int score[10]; 										//��Ŀ�ɼ� 
}STUDENT;
//�����û�����ṹ������ 
typedef struct User										//������������
{
	char name[20];										//�û���
	char password[10];									//����
	struct User *next;									//ָ��ָ����һ���ڵ� 
}user;
//�����������ļ���ͷ
int menu_select();										//�˵�ѡ��
int editmenu();											//���ݱ༭�˵� 
void initialize(STUDENT *x);							//��ʼ��
void input_data(STUDENT stu[],int grade[][11]);			//�������� 
void add_record(STUDENT stu[]);							//���ѧ����Ϣ 
void delete_record(STUDENT stu[]); 						//ɾ��ѧ����Ϣ
void edit_record(STUDENT stu[]);						//�޸�ѧ����Ϣ 
void search_student(STUDENT stu[]);						//��ѯѧ����Ϣ
void search_sex(STUDENT stu[]);							//��ѯ�Ա���Ϣ 
void search_clas(STUDENT stu[]);						//��ѯ�༶��Ϣ 
void search_grade(STUDENT stu[]);						//��ѯ�꼶��Ϣ 
void draw_chart(int grade[][11]);						//����ģ��ֱ��ͼ 
void CreatUser();										//�����û�
user *DeletUser(user *acuser); 							//ɾ���û�
void UpdatePassword(user *acuser);						//�����û����� 
user *log_in();											//��¼����
void save(STUDENT stu[]);								//�ļ����棨���ݵ�����
void load(STUDENT stu[]);								//���ݵ��� 
//����ȫ�ֱ��� 
int MaxNumber=500;										//ȫ�꼶ѧ������ 
int MaxCourse=4;										//��Ŀ����
int grade[10][11];										//ÿ�ſθ��������� 
user *UsHead;											//�����û���ͷ���Ϊȫ�ֱ���
user *InitUser;											//��ʼ���û�ͷ��� 


