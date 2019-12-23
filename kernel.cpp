#include "io.h"
#include "kb.h"
#include "string.h"
#include "cmd.h"


extern "C" void kernelMain(void* multiboot_struct, unsigned int magicNumbers)
{
    clear();

    print("Welcome to MY OS : \n");

    while(true) {
        print("BS_OS> ");
        
        char * buff = readStr();

        char * cmd = getCmd(buff);
        char * rest = getRest(buff);  

        if(streq("clear",cmd)) clear();
        else if(streq("echo",cmd)) {
            print(rest); 
            print("\n");       
        }
        else if(streq("exit",cmd)) {
            clear();            
            print("\n\nShutting down...");

            for(int i = 0;i < 100000000; i++);
            break;
        }
        else print("command not found!\n");
    }

}
