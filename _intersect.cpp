#include<stdio.h>
#include<math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

//���㽻��˻�(P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//�е��Ƿ����߶���,�����˵�
int dot_online_in(point p,point l1,point l2){
 return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}

//���������߶�ͬ��,�����߶��Ϸ���0
int same_side(point p1,point p2,point l1,point l2){
 return xmult(l1,p1,l2)*xmult(l1,p2,l2)>eps;
}

//����ֱ��ƽ��
int parallel(point u1,point u2,point v1,point v2){
 return zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}

//�����㹲��
int dots_inline(point p1,point p2,point p3){
 return zero(xmult(p1,p2,p3));
}

//�����߶��ཻ,�����˵�Ͳ����غ�
int intersect_in(point u1,point u2,point v1,point v2){
 if (!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
  return !same_side(u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
 return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}

//�������߶ν���,�����߶��Ƿ��ཻ(ͬʱ����Ҫ�ж��Ƿ�ƽ��!)
point intersection(point u1,point u2,point v1,point v2){
 point ret=u1;
 double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
   /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
 ret.x+=(u2.x-u1.x)*t;
 ret.y+=(u2.y-u1.y)*t;
 return ret;
}

int main(void)
{
 point u1,u2,v1,v2,ans;
// printf("�������߶�1�������˵�:\n");
// scanf("%lf%lf%lf%lf",&u1.x,&u1.y,&u2.x,&u2.y);
 u1.x = -177,u1.y = 410, u2.x = 512,u2.y = 600;

 printf("�������߶�2�������˵�:\n");
 scanf("%lf%lf%lf%lf",&v1.x,&v1.y,&v2.x,&v2.y);
 if (parallel(u1,u2,v1,v2)||!intersect_in(u1,u2,v1,v2)){
  printf("�޽���!\n");
 }
 else{
  ans=intersection(u1,u2,v1,v2);
  printf("����Ϊ:(%lf,%lf)",ans.x,ans.y);
 }
 return 0;
}