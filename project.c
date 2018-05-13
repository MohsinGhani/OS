/* Process control system calls: The demonstration of fork, execve and wait system cal
ls along with 
zombie and orphan states. 
Implement the C program in which main program accepts the integers to be sorted. 
Main program uses the fork system call to create a new process called a child process. 
Parent process sorts the integers using merge sort and waits for child process using wait 
system call to sort the integers using quick sort. Also demonstrate zombie and orphan 
states.*/ 

#include<stdio.h> 
#include<unistd.h>
#include<sys/types.h>

#define MAX 20 
void mergeSort(int arr[],int low,int mid,int high); 
void partition(int arr[],int low,int high); 
void quicksort(int [10],int,int);

void main() 
{ 
	int a[10],i,n,x;
	printf("\n-------------------------\n"); 
	printf("Enter the no of element:"); 
	scanf("%d",&n); 
	
	for(i=0;i<n;i++){
		printf("Enter the elements no#%d:", i+1); 
		scanf("%d",&a[i]);
	}
	x=fork(); 
	/* fork() 
	create a child process. 
	If fork returns value 0, then it is the child process 
	If it returns some positive number then it is parent process. The positive 		number is the 
	pid of a child. 
	*/ 
	if(x==0) // This part of a if is executed by Child Process 
	{ 
		printf("\nChild Process ID = %d",getpid()); 
		// Pid returns the Pid of the process executing 
		getpid(); //function 
		quicksort(a,0,n-1); // Child calls the quick sort function 
		printf("\nAfter quick sorting elements are: "); 
		for(i=0;i<n;i++) {
			printf(" %d",a[i]); 
		}
	} 
	else // This part of a if is executed by Parent Process 
	{ 
		printf("\nParent Process ID =%d \n",getpid()); 
		partition(a,0,n-1); // Parent process calls Merge Sort function 
		printf("\nAfter merge sorting elements are: "); 
		for(i=0;i<n;i++) {
			printf("%d ",a[i]); 
		}
	}
} // end main

void partition(int arr[],int low,int high) 
{ 
	int mid; 
	if(low<high) 
	{ 
		mid=(low+high)/2; 
		partition(arr,low,mid); 
		partition(arr,mid+1,high); 
		mergeSort(arr,low,mid,high); 
	} 
} 

void mergeSort(int arr[],int low,int mid,int high) 
{ 
	int i,m,k,l,temp[MAX]; 
	l=low; 
	i=low; 
	m=mid+1; 
	while((l<=mid)&&(m<=high)) 
	{ 
		if(arr[l]<=arr[m]) 
		{ 
			temp[i]=arr[l]; 
			l++; 
		} 
		else 
		{ 
			temp[i]=arr[m]; 
			m++; 
		} 
		i++; 
	} 

	if(l>mid) 
	{ 
		for(k=m;k<=high;k++) 
		{ 
			temp[i]=arr[k]; 
			i++; 
		} 
	} 
	else 
	{ 
		for(k=l;k<=mid;k++) 
		{ 
			temp[i]=arr[k]; 
			i++; 
		} 
	} 
	for(k=low;k<=high;k++) 
	{ 
		arr[k]=temp[k]; 
	} 
} 

void quicksort(int x[10],int first,int last) 
{ 
	int pivot,j,temp,i; 
	if(first<last) 
	{ 
		pivot=first; 
		i=first; 
		j=last; 
		while(i<j) 
		{ 
			while(x[i]<=x[pivot]&&i<last) 
			i++; 
			while(x[j]>x[pivot]) 
			j--; 
			if(i<j) 
			{ 
				temp=x[i]; 
				x[i]=x[j]; 
				x[j]=temp; 
			} 
		} 
		temp=x[pivot]; 
		x[pivot]=x[j]; 
		x[j]=temp; 
		quicksort(x,first,j-1); 
		quicksort(x,j+1,last); 
	} 
} 

