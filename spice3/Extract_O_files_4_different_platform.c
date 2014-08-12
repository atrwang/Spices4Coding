#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    printf("fat lib location is : %s\n\n",argv[1]);

    
    char* libPath = argv[1];
    
    FILE * fp;
    char buffer[200];
    
    char lipoInfoCommand[500] = {0};
    strcat (lipoInfoCommand,"lipo -info ");
    strcat (lipoInfoCommand,libPath);
    printf("lipoInfoCommand: %s\n\n", lipoInfoCommand);
    
    fp=popen(lipoInfoCommand,"r");
    fgets(buffer,sizeof(buffer),fp);
    pclose(fp);

    printf("%s\n", buffer);
    
    bool has_i386 = false;
    bool has_x86_64 = false;
    bool has_armv7 = false;
    bool has_armv7s = false;
    bool has_arm64 = false;
    
    //Test i386
    char *has = strstr(buffer, "i386");
    if (has != NULL) {
        has_i386 = true;
    }
    
    //Test x86_64
    has = strstr(buffer, "x86_64");
    if (has != NULL) {
        has_x86_64 = true;
    }
    
    //Test armv7
    has = strstr(buffer, "armv7");
    if (has != NULL) {
        has_armv7 = true;
    }
    
    //Test armv7s
    has = strstr(buffer, "armv7s");
    if (has != NULL) {
        has_armv7s = true;
    }
    
    //Test arm64
    has = strstr(buffer, "arm64");
    if (has != NULL) {
        has_arm64 = true;
    }
    
    printf("has_i386: %d  has_x86_64: %d  has_armv7: %d  has_armv7s: %d  has_arm64: %d\n\n",has_i386,has_x86_64,has_armv7,has_armv7s,has_arm64);
    
    
    //Start to unarchive thin lib to platform dir
    
    /**
     *  //has_i386
     */
    if (has_i386) {
        
        //lipo -thin i386 libMobClickLibrary.a -output libMobClickLibrary-x86_64.a
        char lipoThinCommand[500] = {0};
        strcat (lipoThinCommand,"lipo -thin i386 ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand," -output ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand,"-i386.a");
        
        printf("lipoThinCommand: %s\n\n", lipoThinCommand);
        
        system(lipoThinCommand);
        
        //Make dir
        char mkDirCommand[500] = {0};
        strcat (mkDirCommand,"mkdir ");
        strcat (mkDirCommand,libPath);
        strcat (mkDirCommand,"-i386Dir");
        
        
        printf("mkDirCommand: %s\n\n", mkDirCommand);
        
        system(mkDirCommand);

        
        //unarchive .a to dir  just make
        char unarchiveCommand[500] = {0};
        strcat (unarchiveCommand,"tar xvf ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-i386.a");
        strcat (unarchiveCommand," -C ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-i386Dir");
        
        printf("unarchiveCommand: %s\n\n", unarchiveCommand);
        
        system(unarchiveCommand);
    }
 
    /**
     *  //has_x86_64
     */
    
    if (has_x86_64) {
        
        //lipo -thin i386 libMobClickLibrary.a -output libMobClickLibrary-x86_64.a
        char lipoThinCommand[500] = {0};
        strcat (lipoThinCommand,"lipo -thin x86_64 ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand," -output ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand,"-x86_64.a");
        
        printf("lipoThinCommand: %s\n\n", lipoThinCommand);
        
        system(lipoThinCommand);
        
        //Make dir
        char mkDirCommand[500] = {0};
        strcat (mkDirCommand,"mkdir ");
        strcat (mkDirCommand,libPath);
        strcat (mkDirCommand,"-x86_64Dir");
        
        
        printf("mkDirCommand: %s\n\n", mkDirCommand);
        
        system(mkDirCommand);
        
        
        //unarchive .a to dir  just make
        char unarchiveCommand[500] = {0};
        strcat (unarchiveCommand,"tar xvf ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-x86_64.a");
        strcat (unarchiveCommand," -C ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-x86_64Dir");
        
        printf("unarchiveCommand: %s\n\n", unarchiveCommand);
        
        system(unarchiveCommand);
    }
    
    
    /**
     *  //has_armv7
     */
    
    if (has_armv7) {
        
        //lipo -thin i386 libMobClickLibrary.a -output libMobClickLibrary-x86_64.a
        char lipoThinCommand[500] = {0};
        strcat (lipoThinCommand,"lipo -thin armv7 ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand," -output ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand,"-armv7.a");
        
        printf("lipoThinCommand: %s\n\n", lipoThinCommand);
        
        system(lipoThinCommand);
        
        //Make dir
        char mkDirCommand[500] = {0};
        strcat (mkDirCommand,"mkdir ");
        strcat (mkDirCommand,libPath);
        strcat (mkDirCommand,"-armv7Dir");
        
        
        printf("mkDirCommand: %s\n\n", mkDirCommand);
        
        system(mkDirCommand);
        
        
        //unarchive .a to dir  just make
        char unarchiveCommand[500] = {0};
        strcat (unarchiveCommand,"tar xvf ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-armv7.a");
        strcat (unarchiveCommand," -C ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-armv7Dir");
        
        printf("unarchiveCommand: %s\n\n", unarchiveCommand);
        
        system(unarchiveCommand);
    }
    
    
    /**
     *  //has_armv7s
     */
    
    if (has_armv7s) {
        
        //lipo -thin i386 libMobClickLibrary.a -output libMobClickLibrary-x86_64.a
        char lipoThinCommand[500] = {0};
        strcat (lipoThinCommand,"lipo -thin armv7s ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand," -output ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand,"-armv7s.a");
        
        printf("lipoThinCommand: %s\n\n", lipoThinCommand);
        
        system(lipoThinCommand);
        
        //Make dir
        char mkDirCommand[500] = {0};
        strcat (mkDirCommand,"mkdir ");
        strcat (mkDirCommand,libPath);
        strcat (mkDirCommand,"-armv7sDir");
        
        
        printf("mkDirCommand: %s\n\n", mkDirCommand);
        
        system(mkDirCommand);
        
        
        //unarchive .a to dir  just make
        char unarchiveCommand[500] = {0};
        strcat (unarchiveCommand,"tar xvf ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-armv7s.a");
        strcat (unarchiveCommand," -C ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-armv7sDir");
        
        printf("unarchiveCommand: %s\n\n", unarchiveCommand);
        
        system(unarchiveCommand);
    }
    
    /**
     *  //has_arm64
     */
    
    if (has_arm64) {
        
        //lipo -thin i386 libMobClickLibrary.a -output libMobClickLibrary-x86_64.a
        char lipoThinCommand[500] = {0};
        strcat (lipoThinCommand,"lipo -thin arm64 ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand," -output ");
        strcat (lipoThinCommand,libPath);
        strcat (lipoThinCommand,"-arm64.a");
        
        printf("lipoThinCommand: %s\n\n", lipoThinCommand);
        
        system(lipoThinCommand);
        
        //Make dir
        char mkDirCommand[500] = {0};
        strcat (mkDirCommand,"mkdir ");
        strcat (mkDirCommand,libPath);
        strcat (mkDirCommand,"-arm64Dir");
        
        
        printf("mkDirCommand: %s\n\n", mkDirCommand);
        
        system(mkDirCommand);
        
        
        //unarchive .a to dir  just make
        char unarchiveCommand[500] = {0};
        strcat (unarchiveCommand,"tar xvf ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-arm64.a");
        strcat (unarchiveCommand," -C ");
        strcat (unarchiveCommand,libPath);
        strcat (unarchiveCommand,"-arm64Dir");
        
        printf("unarchiveCommand: %s\n\n", unarchiveCommand);
        
        system(unarchiveCommand);
    }
}
