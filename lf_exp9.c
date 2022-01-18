#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PROFESSIONJUDGE(A) 0==strcmp(A,"Network")?1:(0==strcmp(A,"IOT")?0:2)
//通信 0 网络 1 物联网 2

typedef struct Student
{
    char StudentName[20];
    char Profession[20];
    int EnglishScore;
    int LinearAlgebraScore;
    int CScore;
    int TotalScore;
}Student;

int AverageScore[3]={0,0,0}; //通信 0 网络 1 物联网 2
int PeopleInEachProfession[3]={0,0,0};//英语 0 线代 1 C语言 2

int ReadStudentInfo(const char* filename,Student **pStudents)
{
    FILE *StudentFile=fopen(filename,"r");
    int TotalNum=1;
    int flag=0;
    if(StudentFile==NULL) //file open failed
    {
        printf("File open failed\n");
        return -1;
    }

    while(!feof(StudentFile))
    {
        flag=fgetc(StudentFile); //read a byte from file 
        if(flag=='\n')
           TotalNum++;
    }
    fseek(StudentFile,0,SEEK_SET);
    printf("there are %d students\n",TotalNum);

    *pStudents=(Student*)malloc(TotalNum*sizeof(Student));

    for (int i=0;i<TotalNum;i++)
        fscanf(StudentFile,"%s %s %d %d %d %d\n",(*pStudents)[i].StudentName,(*pStudents)[i].Profession,&(*pStudents)[i].EnglishScore,&(*pStudents)[i].LinearAlgebraScore,&(*pStudents)[i].CScore,&(*pStudents)[i].TotalScore);
    fclose(StudentFile);

    return TotalNum;
}
void Count(Student pStudents[],int num)
{
    Student *student=&pStudents[0];
    for(int i=0;i<num;i++)
    {
        student->TotalScore=student->EnglishScore+student->LinearAlgebraScore+student->CScore;
        switch(PROFESSIONJUDGE(student->Profession))
        {
            case 0: PeopleInEachProfession[0]++;break;
            case 1: PeopleInEachProfession[1]++;break;
            default:
                PeopleInEachProfession[2]++;
        }
        AverageScore[0]+=student->EnglishScore;
        AverageScore[1]+=student->LinearAlgebraScore;
        AverageScore[2]+=student->CScore;
        student++;
    }
    for(int i=0;i<3;i++)
        AverageScore[i]/=num;
    return;
}
void print(Student* pStudents,int Num) //在此处格式化输出 
{
    for (int i=0;i<Num;i++)
        printf("%s %s %d %d %d %d \n",pStudents[i].StudentName,pStudents[i].Profession,pStudents[i].EnglishScore,pStudents[i].LinearAlgebraScore,pStudents[i].CScore,pStudents[i].TotalScore);   
    for(int i=0;i<3;i++)
    {
        printf("Average Score is %d\n",AverageScore[i]);
         printf("People of each profession is %d\n",PeopleInEachProfession[i]);
    }
} 
int main(void)
{
    Student *pStudents;
    char filename[]="student.txt";
    int StudentNum=ReadStudentInfo(filename,&pStudents);
    if(-1==StudentNum)
        exit(-1);
    Count(pStudents,StudentNum);
    print(pStudents,StudentNum);
    free(pStudents);
    return 0;
}