# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define Start 10 
# define End 100 
# define N  2  
 int a[10];  
 void init()
 { 
	 int i; 
	 for (i=0;i<10;i++)
	 { 
		 a[i]=rand()%End; 
		 printf("随机产生要进行寻道的磁道号序列号为：%d\n",a[i]); 
     } 
	 printf("------------------------------------------------------------------------------\n\n\n");
 }
void sort()
 {  
	int i,j,temp;  
	for(i=0;i<10;i++) 
	{     
		for(int j=0;j<9-i;j++)   
			if(a[j]>a[j+1]) 
			{      
				temp=a[j];     
				a[j]=a[j+1];   //大的沉底，小的上浮  
				a[j+1]=temp;   
             } 
     } 
 }
float FCFS()
 { 
	int i,c[10],sum=0; 
	int start=Start; 
	float avg;  
	for (i=0;i<10;i++)
	{ 
		c[i]=abs(start-a[i]); 
		start=a[i]; 
		sum+=c[i]; 
		//printf("第%d次后磁盘移动的磁道总数为%d：\n",i+1,sum);
    }  
	printf("FCFS算法移动的磁道总数为：%d\n",sum);
	avg=float(sum/10.0);
	return avg; 
}
float SSTF() 
{ 
	int i,sum=0,c[10],start=Start,temp,min; 
	float avg; 
	for (i=0;i<10;i++)
	{ 
		for(int j=0;j<10;j++)
		{ 
			min=abs(a[0]-start);
			if(abs(a[j]-start)<min)
			{ 
				min=abs(a[j]-start);
			}  
			temp=j;
		}  
		i=temp; 
		c[i]=abs(start-a[i]); 
		start=a[i];   
		sum+=c[i]; 
   } 
	printf("SSTF算法移动的磁道总数为：%d\n",sum); 
	avg=float(sum/10.0);
	return avg; 
}
float SCAN()
 { 
	int i,c[10],temp=0,sum=0,count=0;  
	int start=Start; 
	float avg;   
	sort(); 
	i=0; 
	while(a[i]<10)
		i++;
	    temp=i; 
	while(start<End+1 )
	{ 
		c[i]=a[i]-start;
		start=a[i];
		sum+=c[i]; 
		i++;
		count++; 
		if(i==10)
			break;
	} 
	i=temp-1; 
	while(start>0)
	{  
		c[i]=start-a[i];
		start=a[i];
		sum+=c[i]; 
		i--; 
		count++; 
		if(count>=10||i<0)
			break;
    }  
	printf("SCAN算法移动的磁道总数为：%d\n",sum);
	avg=float(sum/10.0);
	return avg; 
 }
float CSCAN()
 { 
	int i,c[10],temp,sum=0,count=0; 
	int start=Start;
	float avg;  
	sort(); 
	i=0; 
	while(a[i]<10)
		i++; 
    	temp=i;  
		while(start<End+1)
		{ 
			c[i]=a[i]-start;
			start=a[i];
			sum+=c[i]; 
			i++;  
			count++; 
			if(i==10) 
			{ 
				start=0; 
				i=temp-1; 
			}
            if(count>10)
				break;
        } 
		printf("CSCAN算法移动的磁道总数为：%d\n",sum);  
		avg=float(sum/10.00);
		return avg; 
}
float NStepSCAN()
 {  
	int i,c[10],temp,start=Start,sum=0,number,count;   
	float avg;   
	if(10%N==0)  
		number=10/N; 
	else  
		number = 10/N+1;  
	for(int k=0;i<N;k++) 
	{  
		for(i=0;i<number;i++)    
		{      
			for(int j=0;j<number-1;j++)    
				if(a[j]>a[j+1]) 
				{    
					temp=a[j];   
					a[j]=a[j+1];    
					a[j+1]=temp;  
				}
		} 
	}  
	i=0; 
	while(a[i]<10)
		i++;
	    temp=i; 
		while(start<End+1 )
		{ 
			c[i]=a[i]-start;
			start=a[i]; 
			sum+=c[i];
			i++;
			count++;
			if(i==10)
				break; 
		} 
		i=temp-1; 
		while(start>0) 
		{ 
			c[i]=start-a[i]; 
			start=a[i];
			sum+=c[i];
			i--; 
			count++;
			if(count>=10||i<0)
				break; 
        }  
		printf("NStepSCAN算法移动的磁道总数为：%d\n",sum);
		avg=float(sum/10.00); 
		return avg;
}
void swit( int i)
 { 
	switch(i) 
	{  
	case 0:  
		printf("FCFS\n");  
		break; 
	case 1:  
		printf("SSTF\n");  
		break; 
	case 2:  
		printf("SCAB\n"); 
		break; 
	case 3:  
		printf("CSCAN\n");  
		break; 
	case 4:   
		printf("NStepSCAN\n");  
		break; 
	default: 
		exit(0); 
	}
} 
void main()
 {  
	int i,j; 
	float b[5],d[5],temp; 
	init();  
	b[0]=FCFS(); 
	printf("FCFS算法的平均寻道数为：%3.2f\n",b[0]); 
	printf("********************************************************\n");
	b[1]=SSTF(); 
	printf("SSTF算法的平均寻道数为：%3.2f\n",b[1]); 
	printf("********************************************************\n"); 
	b[2]=SCAN();
	printf("SCAN算法的平均寻道数为：%3.2f\n",b[2]); 
	printf("********************************************************\n"); 
	b[3]=CSCAN(); 
	printf("CSCAN算法的平均寻道数为：%3.2f\n",b[3]); 
	printf("********************************************************\n"); 
	b[4]=NStepSCAN();
	printf("NStepSCAN算法的平均寻道数为：%3.2f\n",b[4]); 
	printf("********************************************************\n\n\n");
	for(i=0;i<5;i++) 
	{    
		d[i]=b[i];
	} 
	for(i=0;i<5;i++)
	{  
		for(j=0;j<5-i;j++)  
			if(d[j]>d[j+1])
			{       
				temp=d[j];    
				d[j]=d[j+1];   
				d[j+1]=temp;   
			}  
	} 
	for(i=0;i<5;i++)
	{  
		if(b[i]==d[4])
		{ 
			printf("此次运行中效率最低的算法是：");  
			swit(i); 
		}  
		if(b[i]==d[0])
		{  
			printf("此次运行中效率最高的算法是：");  
			swit(i);  
        }  
    }
}
