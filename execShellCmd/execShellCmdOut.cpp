#include <stdio.h>
#include <string.h>
#include <iostream>
int main(){
    std::string str_cmd = "ls -al2";
    char outBuffer[1024];  // 保存运行后输出的结果
    //popen创建的管道，默认读取的是标准输出stdout，但很多程序（如ffmpeg相关的）输出到stderr上，
    //为了能方便地读取这些输出，需要在执行命令时，对输出做重定向（<cmd> 2>&1）
    str_cmd += " 2>&1"; 
    const char *cmd = str_cmd.c_str();  // 准备运行的命令
    FILE * pipeLine = popen(cmd,"r");  // 建立流管道
    if(!pipeLine){  // 检测流管道
        perror("Fail to popen\n");
        return 1;
    }
    std::string ret = "";
    while(fgets(outBuffer, 1024, pipeLine) != NULL){ // 获取输出
        printf("输出: %s",outBuffer); // 打印输出
        ret += outBuffer;
    }
    pclose(pipeLine); 
    printf("\n\nret:\n%s \n", ret.c_str());
    return 0;
}
