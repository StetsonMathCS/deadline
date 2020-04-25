#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage:" << endl;
        cout << "./editor <filename>" << endl;
        return EXIT_FAILURE;
    }
    pid_t processId = fork();
    if (processId == 0) {
        char cmd[] = "vim";
        char* const cmd_argv[] = { cmd, argv[1], NULL };
        execvp(cmd, cmd_argv);
        cout << "Unknown command" << endl;
        return EXIT_FAILURE;
    } else if (processId < 0) {
        cout << "Fork failed." << endl;
        return EXIT_FAILURE;
    } else {
        pid_t tpid;
        int child_status;
        tpid = wait(&child_status);
        if(tpid == -1) {
            cout << "Vim didn't exit properly." << endl;
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
