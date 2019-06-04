
/*德才论 (25)

时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
题目描述

宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之

小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”



现给出一批考生的德才分数，请根据司马光的理论给出录取排名。


输入描述:

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格

被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到

但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼

亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。


随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。



输出描述:

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人

总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。


输入例子:

14 60 80

10000001 64 90

10000002 90 60

10000011 85 80

10000003 85 80

10000004 80 85

10000005 82 77

10000006 83 76

10000007 90 78

10000008 75 79

10000009 59 90

10000010 88 45

10000012 80 100

10000013 90 99

10000014 66 60


输出例子:

12

10000013 90 99

10000012 80 100

10000003 85 80

10000011 85 80

10000004 80 85

10000007 90 78

10000006 83 76

10000005 82 77

10000002 90 60

10000014 66 60

10000008 75 79

10000001 64 90  */

//代码如下

#include <iostream>
using namespace std;
void s_ort(int *a,int k)    //排序输出函数
{
    int max_a=0,num=0;
    for(int i=0;i<k;i++)
    {
        max_a=0;num=0;
        for(int j=0;j<k;j++){
        if(*(a+3*j)!=0){
        if(*(a+3*j+1)*100+(*(a+3*j+2))*99>max_a){max_a=*(a+3*j+1)*100+(*(a+3*j+2)*99);num=j;}
        if(*(a+3*j+1)*100+(*(a+3*j+2))*99==max_a){if(*(a+3*j)<(*(a+3*num))){max_a=*(a+3*j+1)*100+(*(a+3*j+2)*99);num=j;}}
    }}
    cout<<*(a+3*num)<<" "<<*(a+3*num+1)<<" "<<*(a+3*num+2)<<endl;
    *(a+3*num)=0;
}}

int main() {
    int k,m,n,k1=0,k2=0,k3=0,k4=0;
    cin>>k>>m>>n;
    int s1[k][3],s2[k][3],s3[k][3],s4[k][3];    //将输入分数分为四种
    for(int i=0;i<k;i++)
    {
        int id,de,cai;
        cin>>id>>de>>cai;
        if(de>=n&&cai>=n){s1[k1][0]=id;s1[k1][1]=de;s1[k1][2]=cai;k1++;}      //判断分类
        if(de>=n&&cai<n&&cai>=m){s2[k2][0]=id;s2[k2][1]=de;s2[k2][2]=cai;k2++;}
        if(de<n&&cai<n&&de>=cai&&de>=m&&cai>=m){s3[k3][0]=id;s3[k3][1]=de;s3[k3][2]=cai;k3++;}
        if(de<n&&de<cai&&de>=m&&cai>=m){s4[k4][0]=id;s4[k4][1]=de;s4[k4][2]=cai;k4++;}
    }
    cout<<k1+k2+k3+k4<<endl;
    s_ort(&s1[0][0],k1);s_ort(&s2[0][0],k2);s_ort(&s3[0][0],k3);s_ort(&s4[0][0],k4);    //调用排序函数输出
}


