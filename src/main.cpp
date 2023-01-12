#include "app/App.h"

int main(int argv, char** args)
{
    zkl::App{}
        .loadSettings()
        .start();
    return 0;
}
