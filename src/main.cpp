#include "app/App.h"

int main(int argv, char** args)
{
    fragmuapte::App{}
        .loadSettings()
        .start();
    return 0;
}
