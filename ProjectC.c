#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct item
{
    char name[50];
    int code;
    float price;
    int noi;
    int type;
}it;//This includes structure and also typedef concept
struct ratings
{
    float service;
    float quality;
    float cost;
};
it a[100];//It is an array of objects
int n=0;
float charge=0.0;
int nt=0;//These include global variables concept
void add()
{
	//Adding items
    n++;
    char tempname[50];
    int tempcode;
    float tempprice;
    int tempnoi;
    int temptype;
    printf("Enter item name\n");
    scanf("%s",tempname);
    strcpy(a[n-1].name,tempname);
    printf("Enter item code\n");
    scanf("%d",&tempcode);
    a[n-1].code=tempcode;
    printf("Enter item price\n");
    scanf("%f",&tempprice);
    a[n-1].price=tempprice;
    printf("Enter number of such items\n");
    scanf("%d",&tempnoi);
    a[n-1].noi=tempnoi;
    printf("Enter item type\n");
    scanf("%d",&temptype);
    a[n-1].type=temptype;
    printf("item added successfully!!\n");
}
void rem()
{
	//Removing items
    printf("Enter item code to be removed\n");
    int tempcode;
    scanf("%d",&tempcode);
    int k;
    int fl=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].code==tempcode)
        {
            k=i;
            fl=1;
            break;
        }
    }
    if(fl==1)
    {
        for(i=k;i<n;i++)
        {
            a[i-1].code=a[i].code;
            a[i-1].price=a[i].price;
            a[i-1].noi=a[i].noi;
            strcpy(a[i-1].name,a[i].name);
            a[i-1].type=a[i].type;
        }
        a[n].code=0;
        a[n].price=0.0;
        a[n].noi=0;
        strcpy(a[n].name," ");
        a[n].type=0;
        n--;
        printf("Item removed successfully!!\n");
    }
    else
    printf("Item could not be found!!\n");
}
void change()
{
    printf("Enter item code\n");
    int tempcode;
    scanf("%d",&tempcode);
    int fl=0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].code==tempcode)
        {
           fl=1;
           printf("Item found, enter new price\n");
           float nprice;
           scanf("%f",&nprice);
           a[i-1].price=nprice;
           printf("Price updated successfully!!\n");
           break;
        }
    }
    if(fl==0)
    printf("Item could not be found!!\n");
}
void swap(int *a,int *b)
{
	//This includes pointer concepts
    *a=(*a)+(*b);
    *b=(*a)-(*b);
    *a=(*a)-(*b);
}
void idswap()
{
    printf("Enter code of items to be swapped\n");
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    int p,q;
    int i;
    int fl=0,fl2=0;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].code==x)
        {
        	p=i;
        	fl=1;
		}
        if(a[i-1].code==y)
        {
        	q=i;
        	fl2=1;
		}
    }
    if((fl==0)&&(fl2==0))
    printf("Atleast one of the items could not be found!!\n");
    else
    {
    	swap(&a[p-1].code,&a[q-1].code);//Only address is passed to function
        printf("Swap successful!!\n");
	}
}
void ee()
{
    printf("Welcome to our Electronic and electrical items section!!\n");
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].type==1)
        {
            printf("Item code = %d\n",a[i-1].code);
            printf("Name = %s\n",a[i-1].name);
            printf("Price = INR %f\n",a[i-1].price);
        }
    }
    while(1)
    {
        printf("Enter item code or 0 to exit\n");
        int chee;
        scanf("%d",&chee);
        int fl=0;
        if(chee==0)
        break;
        for(i=1;i<=n;i++)
        {
            if(a[i-1].code==chee)
            {
                fl=1;
                printf("Enter number of items needed\n");
                int cheen;
                scanf("%d",&cheen);
                if(cheen>a[i-1].noi)
                printf("Out of stock!!\n");
                else
                {
                    nt++;
                    printf("Item purchased!!\n");
                    a[i-1].noi=a[i-1].noi-cheen;
                    charge=charge+cheen*(a[i-1].price);
                }
                break;
            }
        }
        if(fl==0)
        printf("Item does not exist!!\n");
    }    
    printf("Thank you, visit again!!\n");
}
void books()
{
    printf("Welcome to our Books section!!\n");
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].type==2)
        {
            printf("Book code = %d\n",a[i-1].code);
            printf("Name = %s\n",a[i-1].name);
            printf("Price = INR %f\n",a[i-1].price);
        }
    }
    while(1)
    {
        printf("Enter book code or 0 to exit\n");
        int chb;
        scanf("%d",&chb);
        int fl=0;
        if(chb==0)
        break;
        for(i=1;i<=n;i++)
        {
            if(a[i-1].code==chb)
            {
                fl=1;
                printf("Enter number of books needed\n");
                int chbn;
                scanf("%d",&chbn);
                if(chbn>a[i-1].noi)
                printf("Out of stock!!\n");
                else
                {
                    nt++;
                    printf("Book purchased!!\n");
                    a[i-1].noi=a[i-1].noi-chbn;
                    charge=charge+chbn*(a[i-1].price);
                }
                break;
            }
        }
        if(fl==0)
        printf("Book does not exist!!\n");
    }    
    printf("Thank you, visit again!!\n");
}
void food()
{
    printf("Welcome to our Food section!!\n");
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].type==3)
        {
            printf("Food code = %d\n",a[i-1].code);
            printf("Name = %s\n",a[i-1].name);
            printf("Price = INR %f\n",a[i-1].price);
        }
    }
    while(1)
    {
        printf("Enter food code or 0 to exit\n");
        int chf;
        scanf("%d",&chf);
        int fl=0;
        if(chf==0)
        break;
        for(i=1;i<=n;i++)
        {
            if(a[i-1].code==chf)
            {
                fl=1;
                printf("Enter number of food items needed\n");
                int chfn;
                scanf("%d",&chfn);
                if(chfn>a[i-1].noi)
                printf("Out of stock!!\n");
                else
                {
                    nt++;
                    printf("Food item purchased!!\n");
                    a[i-1].noi=a[i-1].noi-chfn;
                    charge=charge+chfn*(a[i-1].price);
                }
                break;
            }
        }
        if(fl==0)
        printf("Food item does not exist!!\n");
    }    
    printf("Thank you, visit again!!\n");
}
void clothes()
{
    printf("Welcome to our Clothes section!!\n");
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i-1].type==4)
        {
            printf("Item code = %d\n",a[i-1].code);
            printf("Name = %s\n",a[i-1].name);
            printf("Price = INR %f\n",a[i-1].price);
        }
    }
    while(1)
    {
        printf("Enter item code or 0 to exit\n");
        int ch;
        scanf("%d",&ch);
        int fl=0;
        if(ch==0)
        break;
        for(i=1;i<=n;i++)
        {
            if(a[i-1].code==ch)
            {
                fl=1;
                printf("Enter number of items needed\n");
                int chn;
                scanf("%d",&chn);
                if(chn>a[i-1].noi)
                printf("Out of stock!!\n");
                else
                {
                    nt++;
                    printf("Item purchased!!\n");
                    a[i-1].noi=a[i-1].noi-chn;
                    charge=charge+chn*(a[i-1].price);
                }
                break;
            }
        }
        if(fl==0)
        printf("Item does not exist!!\n");
    }    
    printf("Thank you, visit again!!\n");
}
int net(int sum,int nox)
{
	//This includes recursive function(recursion) concepts
    if(nox<0)
    return 0;
    else
    return sum+net((sum/10),(nox-1));
}
void edit()
{
	//This includes concepts to edit file
	FILE *fp ; 
    char data[100];
    printf("Enter weekly schedule:\n");
    scanf("%s",data);
    fp=fopen("schedule.txt","w");
	fputs(data,fp);    
    fputs("\n",fp); 
    fclose(fp); 
    printf("Schedule edited successfully!!\n");
}
void view()
{
	//This includes concepts to read file
	FILE *fp ; 
    char data[100];
    fp=fopen("schedule.txt","r");
	while(fgets(data,100,fp)!=NULL) 
    {
    	printf("%s",data);
	}
    fclose(fp); 
}
int main()
{
    while(1)
    {//This includes infinite loop concepts
        printf("Enter mode of access, 1 for admin mode, 2 for customer mode, 3 for ratings mode\n");
        int c1;
        scanf("%d",&c1);
        if(c1==2)
        {//It is client side
            charge=0.0;
            nt=0;
            printf("Welcome to our departmental store!! Please have a look at our items.\n");
            int fl=0;
            while(fl==0)
            {
                printf("1: Electronic and electrical items\n2: Books\n3: Food items\n4: Clothes\n5: Display bill\n6: View schedule\n7: Exit\n");
                int cc1;
                scanf("%d",&cc1);
                switch(cc1)
                {//This includes switch case concepts
                    case 1:ee();break;
                    case 2:books();break;
                    case 3:food();break;
                    case 4:clothes();break;
                    case 5:printf("We have calculated your bill\n");
                           int bill=(int)(charge);
                           bill=net(bill,nt);
                           printf("Total bill after tax = %d\n",bill);break;
                    case 6:view();break;       
                    case 7:fl=1;break;
                    default:printf("Operation failed, please try again!!\n");
                }
            }    
        }   
        else if(c1==1)
        {//It is server side
            printf("Welcome manager!! You may start modifying your departmental store.\n");
            int fl=0;
            while(fl==0)
            {
                printf("1: Add an item\n2: Remove an item\n3: Change item price\n4: Swap code of items\n5: Edit schedule\n6: Exit admin mode\n");
                int ca1;
                scanf("%d",&ca1);
                switch(ca1)
                {//This includes switch case concepts
                    case 1:add();break;
                    case 2:rem();break;
                    case 3:change();break;
                    case 4:idswap();break;
                    case 5:edit();break;
                    case 6:fl=1;break;
                    default:printf("Operation failed, please try again!!\n");
                }
            }    
            
        }
        else if(c1==3)
        {//This includes concepts for using pointers with structure
          struct ratings *ptr;
          ptr=(struct ratings*)malloc(1*sizeof(struct ratings));//It shows dynamic memory allocation concepts
          float a,b,c;
          here:    
            printf("Enter your ratings(out of 5) for our service\n");
            scanf("%f",&a);
            if(a<0.0 || a>5.0)
            {
                printf("Illegal ratings detected, please try again\n");
                goto here;//It shows goto concepts
            }    
            else if(a<2.5)
            printf("We are sorry to hear that, we will try better next time\n");
            else
            printf("Thank you, your satisfaction is our success\n");
            printf("Enter your ratings(out of 5) for our product quality\n");
            scanf("%f",&b);
            if(b<0.0 || b>5.0)
            {
                printf("Illegal ratings detected, please try again\n");
                goto here;
            }  
            else if(b<2.5)
            printf("We are sorry to hear that, we will try better next time\n");
            else
            printf("Thank you, your satisfaction is our success\n");
            printf("Enter your ratings(out of 5) for the price of our products\n");
            scanf("%f",&c);
            if(c<0.0 || c>5.0)
            {
                printf("Illegal ratings detected, please try again\n");
                goto here;
            }  
            else if(c<2.5)
            printf("We are sorry to hear that, we will try better next time\n");
            else
            printf("Thank you, your satisfaction is our success\n");
            ptr->service=a;
            ptr->quality=b;
            ptr->cost=c;
            printf("Thanks for giving all the ratings\n");
            printf("Your ratings have been recorded as follows\n");
            printf("Service = %f/5\nQuality = %f/5\nCost = %f/5\n",ptr->service,ptr->quality,ptr->cost);
        }
        else
        printf("Mode not available, please try again!!\n");
    }
    return 0;
}

