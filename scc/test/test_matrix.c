#include <sys/time.h> 
#include <stdio.h>
#include <stdlib.h>
#define N 500
//N是矩阵维度

void MatrixMultiply(double a[][N], double b[][N], double c[][N])//c=a*b
{
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
		{
			double r=a[i][k];
			for(int j=0;j<N;j+=2)
			{
				c[i][j]+=r*b[k][j];
				c[i][j+1]+=r*b[k][j+1];
			}
		}
}

int main(){
	//c=a×b
	double a[N][N]={0};
	double b[N][N]={0};
	double c[N][N]={0};

	// 准备a，b两个随机生成的矩阵
	srand(1);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			a[i][j]=rand()/(double)(RAND_MAX/10);
			b[i][j]=rand()/(double)(RAND_MAX/10);
			c[i][j]=0;
		}
	//用start和end分别确定开始和结束的时间
	struct timeval start={0,0},end={0,0};
	gettimeofday( &start, NULL );
	MatrixMultiply(a,b,c);
	gettimeofday( &end, NULL );
	//打印反应运算速度的信息
	long timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec; 
	printf("Time use:%ld *10^-6 s\n",timeuse);
	printf("Total size: A:%d,B:%d\n",N*N,N*N);
	printf("Total operators: %d\n",2*N*N*N);
	printf("Element type:double\n");
	printf("My machine INfo: Ubuntu Kylin 16.04 , Intel® Core™ i5-4200U CPU @ 1.60GHz × 4 \n");
	printf("Total Cycles: %ld\n",timeuse*1600);
	printf("Total Cycles/Total operators: %lf\n",((double)timeuse*1600)/((double)2*N*N*N));
}
