#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {

    // Setup //
    // ----- //
    enum ErrorMode {
        WARN,
        WARN_NOPIPE,
        EXIT,
        EXIT_NOPIPE
    };

    // Establish default error mode as 'WARN_NOPIPE'
    enum ErrorMode error_mode = WARN_NOPIPE;

    // Establish default output mode as 'write'
    char output_mode = 'w';

    // Handle input //
    // ------------ //
    char flag;
    while((flag = getopt(argc, argv, "aip:")) != EOF) {
        switch (flag) {
            // Handle append flag
            case 'a':
                output_mode = 'a';
                break;

            case 'i':
                signal(SIGINT, SIG_IGN);
                break;

            // Handle output error behavior flag
            case 'p':
                if (strcmp("warn", optarg) == 0)
                    error_mode = WARN;
                else if (strcmp("warn-nopipe", optarg) == 0) 
                    error_mode = WARN_NOPIPE;
                else if (strcmp("exit", optarg) == 0) 
                    error_mode = EXIT;
                else if (strcmp("exit-nopipe", optarg) == 0) 
                    error_mode = EXIT_NOPIPE;
                else {
                    fprintf(stderr, "Unknown option for -p flag: '%s'\n", optarg);
                    return 1;
                };

                break;

            // Handle invalid flag
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        };
    }


    // Handle Output //
    // ------------- //

    // Open all files
    FILE *files[argc - optind];
    // FILE * file;
    for (int i = 0; i < argc - optind; i++) {
        files[i] = fopen(argv[optind + i], &output_mode);
    }
    unsigned long num_files = sizeof(files) / sizeof(files[0]);
    // file = fopen(argv[argc-optind], &output_mode);

    // Copy input into all files
    char input[80];

    while (fgets(input, 80, stdin) > 0) {
        printf("%s", input);
        for(int i = 0; i < num_files; i++) fprintf(files[i], "%s", input);
    }

    // Close all files
    for(int i = 0; i < num_files; i++) fclose(files[i]);

    return 0;
}
