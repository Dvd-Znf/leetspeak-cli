# leetspeak-cli [NO LONGER MAINTAINED]
Simple program that will grant you the ability to speak the eleet language from your favorite shell.  
     
## DEPRECATION NOTICE:     
This repo hasn't been updated in a while so it isn't under active development anymore!        
<3        
## Help  
```
Usage: leet <command> <args>

Concatenate standard input to standard output.
When leet is not piped to another program/file it will read std input.

Posible command options:
		-h | --help : Display this message
 -f <path> | --file <path> : Read input from a file
	-g | --figlet	    : Use figlet (THIS REQUIRES FIGLET TO BE INSTALLED)
	-l | --lolcat	    : Use lolcat (THIS REQUIRES LOLCAT TO BE INSTALLED)
		-x | -X	    : Add xX before content and Xx after

Examples:
	leet -f FILE.txt	Output the content of FILE.txt
   echo Hello! | leet -g	Display the message 'H3ll0!' with figlet
	leet -f FILE -l -g	Show contents of FILE with lolcat and figlet and leet
```
  
## Build and install from source
Step 0:   

Clone this repo  
  
Step 1:
```sh
$ sudo make install
```
  
Thats all!
## Uninstall
```sh
$ sudo make uninstall
```
