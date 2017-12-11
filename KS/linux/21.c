/*
1.【代码题】
编程统计指定目录下普通文件个数。包括其子目录下的普通文件，将文件总数打印至屏

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
int getfilenum(const char * f)
{
    DIR * temp = opendir(f);
    if(temp ==NULL)
    {
        return 0;
    }
    int num =0;
    struct dirent * file=NULL;
    while((file =readdir(temp))!=NULL)
    {
        if(strcmp(".", file->d_name) == 0 || strcmp("..", file->d_name) == 0)//如果是..和.类型
        {
            continue;
        }
        int ret =1;
        char buf[1024]={0};
        if(file->d_type == DT_DIR)
        {
            sprintf(buf,"%s/%s",f,file->d_name);
            ret =getfilenum(buf);
        }
        num += ret;
    }
    printf("%s的文件个数为%d\n",f,num);
    return num;
}



int main(int argc,char * argv[])
{
    int ret =0;
    if( argc !=2)
    {
        printf("请输入文件路径\n");
        return 0;
    }
    //ret = chdir(argv[1]);
    if(ret==-1)
    {
        printf("文件路径错误");
        return  10;
    }
    ret =getfilenum(argv[1]);
    return 0;
}
