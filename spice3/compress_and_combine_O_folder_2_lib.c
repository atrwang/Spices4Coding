#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    
    printf("start archive \n\n");
    
    for (int i = 1; i< argc; i++) {
        char* OfileDir = argv[i];
        
        
        //archive O folder to .a
        
        //libtool -static *.o -o ../libMobClickLibrary-x86_64.a
        char   archiveCommand[500] = {0};
        strcat (archiveCommand,"libtool -static ");
        strcat (archiveCommand,OfileDir);
        strcat (archiveCommand,"/*.o ");
        strcat (archiveCommand," -o ");
        strcat (archiveCommand,OfileDir);
        strcat (archiveCommand,"-new.a");
        
        printf("archiveCommand: %s\n\n", archiveCommand);
        
        int status = system(archiveCommand);


//        FILE *  fp=popen(archiveCommand,"r");
//        pclose(fp);
    }
    
    
    
    printf("start combination\n\n");
    
    //lipo -create libProprietary-armv6.a libProprietary-i386.a -output libProprietary-noKissXML.a
    
    //Combine them to
    
    char   combineCommand[500] = {0};
    strcat (combineCommand,"lipo -create ");
    
    for (int i = 1; i< argc; i++) {
        char* OfileDir = argv[i];
        
        //combine .a to fat .a
        strcat (combineCommand,OfileDir);
        strcat (combineCommand,"-new.a ");
        
        
    }
    
    strcat (combineCommand," -output ");
    
    char*sepPath = strtok(argv[1], ".a");
    char   destinationPath[500] = {0};
    strcat (destinationPath,sepPath);
    strcat (destinationPath,"-final_combined.a");
    
    
    strcat (combineCommand,destinationPath);
    
    printf("combineCommand: %s\n\n", combineCommand);
    int status = system(combineCommand);
    
    
    printf("*********************************\n\n");
    
    if (status == 0) {
        printf("final combined static library is : %s\n\n", destinationPath);
    }else {
        printf("final combined static library failed!!!!!\n\n");
    }
    
    printf("*********************************\n\n");
    
}
