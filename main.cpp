#include <iostream>
#define MAX 100
using namespace std;
int arr[MAX],n,p;
int rear;
int binarysearch(int *,int,int,int);
int extractmini(int,int,int *);
int selectionsort(int *,int);
int binarysearch(int *arr,int start,int enda,int q,int l)
{

    int mid=(start+enda)/2;
   // cout<<mid<<" \n";
    if(start>enda) return (-1);
    if(start==enda)
    {
        //cout<<"in if\n";
        if(arr[start]==q)
        {

            cout<<"one value present matches the value to be searched";
            arr[start]=l;


        }
        else
        {

            cout<<"\nvalue not found\n";
        }
    }
    else
    {
        //cout<<"in else\n";
        if(arr[mid]==q)
        {


            //cout<<"value is at "<<mid<<"th position"<<endl;
            arr[mid]=l;

        }
        else if(arr[mid]<q)
        {

            return binarysearch(arr,mid+1,rear,q,l);
        }
        else

            return binarysearch(arr,start,mid-1,q,l);
    }

}


int selectionsort(int *ar,int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ar[i]>arr[j])
            {
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }

        }


    }

    return *ar;


}



int extractmini(int rear,int n,int *arr)
{
    int i=0;

    while(rear!=0)
    {

        cout<<"element is= "<<arr[0];
        for(i=0; i<rear; i++)
        {
            arr[i]=arr[i+1];





        }
        rear--;
        cout<<"\nrear="<<rear<<endl;
        return rear;

    }
    if(rear==0) cout<<"********Queue is empty*********"<<endl;
    return rear;



}
int main()
{

    int n,x,i=0;
    int frontq=0;


    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    rear=n;
    for( i=0; i<n; i++)
    {
        cout<<"Enter the "<<i+1<<" th element"<<endl;
        cin>>arr[i];

    }
    selectionsort(arr,n);

    cout<<"final queue is --"<<endl;
    for( i=0; i<n; i++)
    {
        cout<< arr[i]<<" ";

    }
    cout<<"\nrear="<<rear;
    int p,s,q,l;
    do
    {
        cout<<"\n--------MAIN MENU-----------"<<endl;
        cout<<"\nPress 1 to extract minimum"<<endl;
        cout<<"Press 2 to insert element"<<endl;
        cout<<"Press 3 to decrease key element"<<endl;
        cout<<"Press 4 to display"<<endl;
        cout<<"press 0 to exit"<<endl;
        cin>>p;
        switch(p)
        {
        case 1:
            s=extractmini(rear,n,arr);
            rear=s;

            break;
        case 2:
            cout<<"Inserting element at"<<rear<<" position";
            cout<<"\nEnter the value ";
            cin>>x;
            arr[rear]=x;
            rear++;
            selectionsort(arr,rear);
            for( i=0; i<rear; i++)
            {
                cout<< arr[i]<<" ";

            }

            break;
        case 3:
            cout<<"Enter the number you want to replace"<<endl;
            cin>>q;
            cout<<"Enter the new value you want to replace"<<endl;
            cin>>l;
            if(q<l) cout<<"!!!!Cannot do this operation as the new value entered is larger"<<endl;
            else
            {

                binarysearch(arr,0,rear,q,l);
                selectionsort(arr,rear);
                for(i=0; i<n; i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            break;
        case 4:
            cout<<"QUEUE IS = ";
            for(i=0;i<rear;i++)
            {

                cout<<arr[i]<<" ";


            }
            cout<<endl;
            break;

        default:
            cout<<"Invalid-input"<<endl;
            break;
        }

    }
    while(p!=0);



    return 0;
}
