#include <cstdio>
#include <cstdlib>
/**
 * Handle command lines with arguments
 *
 */
int Simple_shell_0.1(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Insufficient arguments.\n");
        return 1;
    }

    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[2]);

    int sum = num1 + num2;
    int difference = num1 - num2;

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);

    return 0;
}
