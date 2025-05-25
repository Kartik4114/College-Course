#include<stdio.h>
#include<time.h>

// int count=0;
void helper(int arr[],int s,int mid,int e){

int l=mid-s+1;
int r=e-mid;
int arr1[l],arr2[r];

for (int i = 0; i < l; i++)
{
    arr1[i]=arr[i+s];

}
for (int i = 0; i < r; i++)
{
    arr2[i]=arr[i+mid+1];
}

int i=0,j=0;
int k=s;

while (i<l && j<r)
{
    if(arr1[i]<=arr2[j]){
        arr[k]=arr1[i];
        i++;
    }
    else{
        arr[k]=arr2[j];
        j++;
        // count++;
        
    }
    k++;
}

while (i<l)
{
    arr[k]=arr1[i];
    i++;
    k++;
}
while (j<r)
{
    arr[k]=arr2[j];
    j++;
    k++;
}

// printf("Count %d",count);

}
void merge(int arr[],int s,int e){
    
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    merge(arr,s,mid);
    merge(arr,mid+1,e);
    helper(arr,s,mid,e);
}
void merge_sort(int arr[],int n){

    merge(arr,0,n);
}
 int main(){

    int n;
    scanf("%d",&n);
    clock_t start,end;

    int arr[n];

    for (int i = 0; i < n;i++ )
    {
        scanf("%d",&arr[i]);
    }

    start=clock();
    merge_sort(arr,n);
    end=clock();

    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    double time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time is %lf",time);
    
    
    return 0;
}