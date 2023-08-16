#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;
    char *prompt = "myshell> ";

    // Initialisiere die Readline-Bibliothek für die Befehlshistorie
    using_history();

    while ((input = readline(prompt)) != NULL) {
        // Füge den eingegebenen Befehl zur Befehlshistorie hinzu
        add_history(input);

        // Überprüfe, ob der Befehl "history" ist
        if (strcmp(input, "history") == 0) {
            HIST_ENTRY **hist_list = history_list();
            if (hist_list) {
                for (int i = 0; hist_list[i]; i++) {
                    printf("%d: %s\n", i + history_base, hist_list[i]->line);
                }
            }
        }

        // Gib die eingegebene Zeile und eine neue Zeile für die Benutzereingabe aus
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();

        free(input);
    }

    // Beende die Verwendung der Readline-Bibliothek für die Befehlshistorie
    //free_history();

    return 0;
}
