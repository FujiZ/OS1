#ifndef _global_H
#define _global_H

#ifdef	__cplusplus
extern "C" {
#endif   
    
    #define HISTORY_LEN 10
    
	#define MAXSIZE 100
	
    #define STOPPED "stopped"
    #define RUNNING "running"
    #define KILLED  "killed"
    #define DONE    "done"

    #include <stdio.h>
    #include <stdlib.h>
    #include <glob.h>
	
    typedef struct SimpleCmd {
        int isBack;     // 是否后台运行
        char **args;    // 命令及参数
        char *input;    // 输入重定向
        char *output;   // 输出重定向
    } SimpleCmd;

    typedef struct History {
        int start;                    //首位置
        int end;                      //末位置
        char cmds[HISTORY_LEN][200];  //历史命令
    } History;

    typedef struct Job {
        int pid;          //进程号
        char cmd[100];    //命令名
        char state[10];   //作业状态
        struct Job *next; //下一节点指针
    } Job;
    
    char inputBuff[200];  //存放输入的命令
    int inPipe,outPipe;   //存放pipe的输入输出指针
    void init();
    void addHistory(char *history);
    void execute(int i,int j);
	void execute_cmplx();
	char dp_match( const char *str1, const char *str2);//通配符处理
	int contain_wildcard(char* str);
	char* find_dir(char* str);
	char* find_file(char* str);
	int replace_cmd(SimpleCmd &cmd,int i,glob_t &gl);
#ifdef	__cplusplus
}
#endif

#endif	/* _global_H */
