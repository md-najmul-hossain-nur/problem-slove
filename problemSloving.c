//Question

//The purpose of this C program is to demonstrate different sorting and searching algorithms. Users can input an array
//of integers either manually or randomly. The program sorts the array using bubble sort, insertion sort, or selection sort,
//and allows searching for a specific item using linear or binary search. Additionally, it checks if an item is odd or even,
//calculates the total sum of array elements, and finds the maximum and minimum values. Results are displayed on the console and saved to a file.

//-------------------------------------------------------------------0--------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void linar_search( int a[], int n, int item,FILE *ok)
{
    int found=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==item)
        {
            printf("\n %d is found at index %d.\n",item,i);
            fprintf(ok,"\n found at ondex %d\n",item,i);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("\nNot found.\n");
        fprintf(ok,"\n Not found.\n");
    }
}
void bubble_sort(int a[],int n,FILE *ok)
{
    int temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\n After  Bubble sort\n");
    fprintf(ok,"\nAfter Bubble sort \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", a[i]);
        fprintf(ok,"%d ", a[i]);
    }

}
int odd_even( int item,FILE *ok)
{
    if(item%2==0)
    {
        printf("\n %d is Even \n",item);
        fprintf(ok,"\n %d is Even \n",item);
    }
    else
    {
        printf("\n %d is odd\n",item);
        fprintf(ok,"\n %d is odd\n",item);
    }
}
int binary_search(int a[], int n, int item, FILE *ok)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == item)
        {
            return mid;
        }
        else if (a[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void selection_sort(int a[], int n, FILE *ok)
{
    int min_id, t;
    for (int i = 0; i < n - 1; i++)
    {
        min_id = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_id])
            {
                min_id = j;
            }
        }

        t = a[min_id];
        a[min_id] = a[i];
        a[i] = t;
    }

    printf("\nAfter selection sort:\n");
    fprintf(ok, "\nAfter selection sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        fprintf(ok, "%d ", a[i]);
    }
    printf("\n");
}

void insertion_sort(int a[], int n, FILE *ok)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("\nAfter insertion sort:\n");
    fprintf(ok, "\nAfter insertion sort:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        fprintf(ok, "%d ", a[i]);
    }
    printf("\n");
}
void sum(int a[], int n, FILE* ok)
{
    int total_sum=0;

    for(int i=0; i<n; i++)
    {
        total_sum+=a[i];

    }
    printf("\nTotal sum is %d \n", total_sum);
    fprintf(ok,"\nTotal sum is %d \n", total_sum);
}
void max_min(int a[],int n,FILE *ok)
{
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        else if (a[i] > max)
            max = a[i];
    }
    printf("min-%d max-%d\n", min, max);
}

int main()
{

    int a[100],n,item,choose,choice,sort;
    FILE *ok=fopen("Problem.text","w");
    if(ok==NULL)
    {
        printf("\nFile is Error\n");
        return 1;
    }
    printf("Enter size: ");
    scanf("%d",&n);
    printf("\n1.User input\n2. Random value\n ");
    fprintf(ok,"\n1.User input\n2. Random value\n ");
    scanf("%d",&choice);
    if(choice==1)
    {
        for(int i=0; i<n; i++)
        {
            printf("Enter the element: ");
            scanf("%d",&a[i]);
            fprintf(ok,"Enter the element: ");
        }
    }
    else if( choice==2)
    {
        srand(time(NULL));
        for(int i=0; i<n; i++)
        {
            a[i]=(rand()%100)+1;
            printf(" %d ",a[i]);
            fprintf(ok,"%d ",a[i]);
        }
    }
    else
    {
        printf("Enter Wrong Number!!!! ");
        fprintf(ok,"Enter Wrong Number!!!! ");
    }
    printf("\nEnter sorting Choose: \n");
    fprintf(ok,"\nEnter sorting Choose: \n");
    printf("\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n" );
fprintf(ok,"\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n" );
    scanf("%d",&sort);
    if(sort==1)
    {
        bubble_sort(a,n,ok);
    }
    else if(sort==2)
    {
        insertion_sort(a, n, ok);
    }
    else if(sort==3)
    {
        selection_sort(a,n,ok);
    }
    else
    {
        printf("Enter WRomg Number!!");
        fprintf(ok,"Enter WRomg Number!!");
    }

printf("\nEnter searching number: \n");
fprintf(ok,"\nEnter searching number : \n");
scanf("%d",&item);
printf("Enter which Searching you use: \n");
fprintf(ok,"Enter which Searching you use: \n");
printf("\n1.Liner Search(odd_even)\n2.Binary Search(sum, max_min)\n3.Plan-B(odd/even, max/min, sum\n" );
fprintf(ok,"\n1.Liner Search\n2.Binary Search\n3.Plan-B\n" );
scanf("%d",&choose);
if(choose == 1)
{

    linar_search(a,n,item,ok);
    odd_even(item,ok);
}
else if (choose == 2)
{
    int index = binary_search(a, n, item, ok);
    if (index != -1)
    {
        printf("\n %d is found at index %d.\n", item, index);
        fprintf(ok,"\nFound %d at index %d.\n", item, index);
    }
    else
    {
        printf("\nNot found.\n");
        fprintf(ok,"\nNot found.\n");
    }
    sum(a, n, ok);
    max_min(a, n, ok);
}

else if( choose== 3)
{
    linar_search(a,n,item,ok);
    odd_even(item,ok);
    sum(a,n,ok);
    max_min(a,n,ok);
}
fclose(ok);
return 0;
}


