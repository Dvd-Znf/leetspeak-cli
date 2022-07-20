#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


const char idstr[] = {		//This is the index of what character will be replaced
	'4', //A | a
	'!', //I | i
	'@', //O
	'0', //o
	'$', //S
	'5', //s
	'3', //e

};

static char helpstr[] = "\n"
			"Usage: leet <command> <args> \n"
			"\n"
			"Concatenate standard input to standard output.\n"
			"When leet is not piped to another program/file it will read std input.\n"
			"\n"
			"Posible command options:\n"
			"		-h | --help : Display this message\n"
			" -f <path> | --file <path> : Read input from a file\n"
			"	-g | --figlet	    : Use figlet (THIS REQUIRES FIGLET TO BE INSTALLED)\n"
			"	-l | --lolcat	    : Use lolcat (THIS REQUIRES LOLCAT TO BE INSTALLED)\n"
			"		-x | -X	    : Add xX before content and Xx after\n"
			"\n"
			"Examples:\n"
			"	leet -f FILE.txt	Output the content of FILE.txt\n"
			"   echo Hello! | leet -g	Display the message 'H3ll0!' with figlet\n"
			"	leet -f FILE -l -g	Show contents of FILE with lolcat and figlet and leet\n"
			"\n";


int main(int argc, char* argv[])
{
	char str[255] = "", strout[255] = "", pathinst[255] = "cat "; 
	bool skp = false,	//Defaults are false, feel free to change them 
	       f = false, 
	       g = false, 
	       l = false,
	       x = false;	


	for (int i = 1; i < argc; ++i){
		
		if(string(argv[i]) == "-h" || string(argv[i]) == "--help"){
			cout<<helpstr;
			return 0;
		} else 
		if(string(argv[i]) == "-f" || string(argv[i]) == "--file"){
			if(i+1<argc){
				// char pathinst[255] = "cat ";
				strcat(pathinst,argv[i+1]);
				strcat(pathinst," | leet");
				f = true;
				skp = true;
			} else {
				cout<<"Error: Expected additional argument <path>\n";
				return 1;
			}
		} else 
		if(string(argv[i]) == "-g" || string(argv[i]) == "--figlet"){
			
			g = true;
			skp = true;
			
		} else  
		if(string(argv[i]) == "-l" || string(argv[i]) == "--lolcat"){
			l = true;
			skp = true;
		} else  
		if(string(argv[i]) == "-x" || string(argv[i]) == "-X"){
			x = true;
			//skp = true;
		}
	}

	char execinst[50] = "leet";			//Is this considered 'Recursion'?
	
	if(skp == true){
		if(x == true)
			strcpy(execinst, "leet -x");
		if(f == true)
			strcpy(execinst,pathinst);
		if(g == true)
			strcat(execinst," | figlet");
		if(l ==true)
			strcat(execinst," | lolcat");
		system(execinst);
	} else {
	cin.getline(str,255);
	}

	


	for(int i=0;i<strlen(str);i++){
		if(strchr("A",str[i]) || strchr("a",str[i])){
			strout[i]=idstr[0];
		} else if(strchr("I",str[i]) || strchr("i",str[i])){
			strout[i]=idstr[1];
		} else if(strchr("O",str[i])){
			strout[i]=idstr[2];
		} else if(strchr("o",str[i])){
			strout[i]=idstr[3];
		} else if(strchr("S",str[i])){
			strout[i]=idstr[4];
		} else if(strchr("s",str[i])){
			strout[i]=idstr[5];
		} else if(strchr("e",str[i])){
			strout[i]=idstr[6];
		} else {
			strout[i]=str[i];
		}
		
	}
	
	if(x == true && skp != true ){
		char xstr[255] = "xX";
		strcat(xstr,strout);
		strcat(xstr,"Xx");
		strcpy(strout,xstr);
	}
	
	cout<<strout<<"\n";

	

	return 0;
}
