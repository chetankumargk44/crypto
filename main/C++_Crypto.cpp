#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
void texttonumber(int);
void numbertotext(int);

char riteversion[5]="v4.01";

int modulus(int nos)
{
	if(nos<0)
   {
   	nos*=-1;
   }
   return nos;
}
//Forms the Diffie Hellman Keygen
int dhm_keygen()
{
	randomize();
   int usernos,silverkey,p,g,goldenkey;
   cout<<"Do you have the security number and security passkey?\nEnter 1 for no and 0 for yes.";
   int choice1;
   cin>>choice1;
   do
   {
   	if(choice1==1)
	   {
   	   cout<<"\nAlright, we'l generate one for you.";
      	g=random(5)+4;
	      //This mechanism would find a prime number p
   	   int primenos[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
      	p=primenos[random(25)];
	      cout<<"\nYour security number is: "<<p<<" and security passkey is "<<g;
   	}
	   else if(choice1==0)
   	{
      	cout<<"\nEnter security number:";
	   	cin>>p;
   	   cout<<"\nEnter security passkey:";
      	cin>>g;
	   }
   	else
	   {
      	cerr<<"\nERROR. Invalid Input";
      }
   }while((choice1!=1)&&(choice1!=0));
   usernos=random(7)+4;
   silverkey=modulus(fmod(pow(g,usernos),p));
   cout<<"\n Your Silver Key is "<<silverkey;
   cout<<"\nShare these details with your counterpart.";
   cout<<"\nEnter your counterparts Silver Key?:";
   cin>>silverkey;
   goldenkey=modulus(fmod(pow(silverkey,usernos),p));
   cout<<"\nOkay, we're set for encryption/decryption.";
   return(goldenkey);
}

//Void Main begins
void main()
{
  char ch,repeat='y';int goldenkey;
  cout<<"\nCrypto "<<riteversion<<" by NK7";
  cout<<"\nThis is a cryptograph program. Before you encrypt your message, ";
  goldenkey=dhm_keygen();
  do
  {
  		clrscr();

      cout<<"\nEnter:-";
      cout<<"\n \t 1 if you want to convert number to text.";
      cout<<"\n \t 2 if you want to convert text into number.\n";
  		cin>>ch;
     	if(ch==50)
     	{
        texttonumber(goldenkey);
     	}
    	else if(ch==49)
     	{
          numbertotext(goldenkey);
      }
      else
      {
      	cerr<<"\nError in input";
         for(long int wait=0;wait<99999999;wait++);
        	goto redo;
      }
      cout<<"\n To copy the output:";
      cout<<"\n1. Press Ctrl-M on your keyboard";
      cout<<"\n2. Select the output.";
      cout<<"\n3. Press the Enter key. Your output is pasted on the clipboard. ";
      cout<<"\n4. For speedy copy-and-pasting, please check the QuickEdit box in the Properties of this window.\nThe Properties section can be accessed by right clicking the title bar, and clicking Properties menu.";
      cout<<"\n\n\n\nNow, do you wish to repeat?";
      cout<<"\nEnter Y for yes and anything else if you want to quit:- \n";
      cin>>repeat;
     	redo:
     	}while((repeat=='y')||(repeat=='Y'));
  cout<<"\nTERMINATING.Version ";
  puts(riteversion);
  cout<<" NK7 Devs. The app is by all means, peaceful, and is an experimental coding project by our team thats all.";
  }
 exit(0);
  getch();
}
//Text to Number
void texttonumber(int goldenkey)
{
  	int output;
  	char input[100];
  	randomize();
	cout<<"\nText to number. Sweet.";
	cout<<"\nEnter your text (max 100 characters) - \n";
 	gets(input);
   int randomnos,addingfactor;
   randomnos=random(1000);
   addingfactor=randomnos+100;
   clrscr();
  	cout<<"\nOUTPUT \n--\n";
 	for(int i=0;input[i]!='\0';i++)
 	{
		output=input[i]+(pow(-1,i)*2*i);
    	cout<<(output+addingfactor)<<".";
  	}

   addingfactor+=(goldenkey);
	cout<<"\b."<<(addingfactor-7)<<"."<<riteversion[1]<<"\n--";
	return;
}
//Number to Text
void numbertotext(int goldenkey)
{
	char input2[500];
  	int i,num[100];
  	cout<<"\nNumber to text. Sweet.";
   cout<<"\nEnter your number here:- \n";
   error1:
  	gets(input2);
   cout<<"\n";
   for(i=0;input2[i]!='\0';i++)
   {
   	if(!isdigit(input2[i]))
     {
      	if(input2[i]!='.')
         {
         	cerr<<"\nThat was an error there.";
            goto error1;
         }
     }
   }
  	for(i=0;i<100;i++)                         //Resetting all values of num[i] to 0
  	{
  		num[i]='\0';
  	}
  	int k=0;
  	for(i=0;input2[i]!='\0';i++)
  	{
     if(input2[i]=='.')
  	  {
     		++k;
     }
     else
     	{
     		num[k]=(num[k]*10)+input2[i]-48; //48 is to convert the decimal "6" into human 6.
   	   //cout<<"\n num["<<k<<"]="<<num[k]<<endl;
     	}
  	}
  clrscr();
  cout<<"\nOUTPUT\n--\n";
  int subtractingfactor;
  for(i=0;num[i]!=0;i++)
  {
  		if((num[i+2]==0)&&(num[i+1]!=0))
      {
         subtractingfactor=num[i]+7;
      }
   }

  //cout<<"\ntsum="<<goldenkey;
  subtractingfactor-=(goldenkey);
  //cout<<"\nSubtracting Factor after goldenkey= "<<subtractingfactor<<"\n";
  for(int k=0;num[k+2]!=0;++k)
  {

     	char chara;
  		chara=num[k]-subtractingfactor-(pow(-1,k)*2*k);
  		cout<<chara;
  }
  	cout<<"\n--";
	return;
}
