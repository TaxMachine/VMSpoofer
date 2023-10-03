#include <unistd.h>
#include <pthread.h>

/**
 * @brief Literally does nothing.
 */
void* decoy() {
    while (1) {
        sleep(10000);
    }
}

/**
 * @brief This is the most optimized way to do nothing.
 */
int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, decoy, NULL);
    pthread_join(thread, NULL);
    return 0;
}