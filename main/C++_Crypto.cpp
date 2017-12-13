#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
void texttonumber();
void numbertotext();
int incompatible=1,i;
char riteversion[5]="v3.00",site[]="https://drive.google.com/drive/folders/0B4WtzuPF3XojNF9icENvYzdGUFk";
void main()
{
  char ch,repeat='y';
  do
  {
  		clrscr();
      cout<<"\nCryptographer v3.01 by NirmalK7";
  		cout<<"\nThis is a cryptograph program.";
      cout<<"\nEnter:-";
      cout<<"\n \t 1 if you want to convert number to text.";
      cout<<"\n \t 2 if you want to convert text into number.\n";
  		cin>>ch;
     	if(ch==50)
     	{
        texttonumber();
     	}
    	else if(ch==49)
     	{
          numbertotext();
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
 // }
 exit(0);
  getch();
}
//--------------------------------TEXT TO NUMBER--------------------------------------
void texttonumber()
{
  	int tsum=0,output;
  	char input[100],data[16];
   cout<<"\nEnter your name:";
   cin>>data;
   for(i=0;data[i]!='\0';i++)
   {
      tsum+=data[i];
  	}
	cout<<"\n";
   randomize();
	cout<<"\nText to number. Sweet.";
	cout<<"\nEnter your text (max 100 characters) - \n";
 	gets(input);
   int randomnos,addingfactor;
   randomnos=random(1000)+100;
   clrscr();
  	cout<<"\nOUTPUT \n--\n";
 	for(int i=0;input[i]!='\0';i++)
 	{
		output=input[i]+(pow(-1,i)*2*i);
    	cout<<(output+randomnos)<<".";
  	}

   randomnos+=(tsum);
	cout<<(randomnos-7)<<"."<<riteversion[1]<<"\n--";
	return;
}
//-----------------------------------------NUMBER TO TEXT-----------------------------
void numbertotext()
{
	char input2[500],sendername[10];
  	int i,num[100],tsum=0;
  	cout<<"\nNumber to text. Sweet.";
   for(i=0;i<10;i++)
   {
   	sendername[i]='\0';
   }
   errorA:
   cout<<"\nEnter the sender's name:- ";
   gets(sendername);
   clrscr();
   cout<<endl;
   for(i=0;sendername[i]!='\0';i++)
   {
     	tsum+=sendername[i];
   }
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
  	int k=0,negativenos=0;
  	for(i=0;input2[i]!='\0';i++)
  	{
     //cout<<"\n input2["<<i<<"]="<<input2[i];
     if(input2[i]=='.')
  	  {
     		++k;
     }
     else
     {
     		num[k]=(num[k]*10)+input2[i]-48; //-48 is to convert the decimal "6" into human 6.
     }
  	}
  clrscr();
  cout<<"\nOUTPUT\n--\n";
  int subtractingfactor;
  for(i=0;num[i]!=0;i++)
  {
  		if((num[i+2]==0)&&(num[i+1]!=0))
      {
         subtractingfactor=num[i]-tsum+7;
         if(num[i+1]-(riteversion[1]-48)>=1)
      	{
      		cout<<"\nSorry, the code conversion cannot be done by this program of version ";
         	puts(riteversion);
         	cout<<"\nApologies for the inconvienience. Enter any key to open the link.";
            for(int w=0;w<999999999;w++);
         	ShellExecute(NULL, "open", site ,NULL, NULL, SW_SHOWNORMAL);
            clrscr();
            cout<<"TERMINATING. Cryptographer ";
            puts(riteversion);
            cout<<" by NirmalK7.\nThe app is by all means, peaceful, and is an experimental coding project by our team thats all.";
            getch();
            exit(0);
     		}
      }
   }

  for(int k=0;num[k+2]!=0;++k)
  {

     	char chara;
  		chara=num[k]-subtractingfactor-(pow(-1,k)*2*k);
  		cout<<chara;
  }
  	cout<<"\n--";
	return;
}
