#include "../includes/sleepwipe.h"

int main(int ac, char **av)
{
    /* Uyku önleme işlemi için kullanılacak ID tanımlanıyor. */
    IOPMAssertionID assertionID;
    /* Aktivitenin nedenini tanımlayan bir CFStringRef oluşturuluyor. */
    CFStringRef reasonForActivity= CFSTR("Prevent system sleep");
    /* Uyku önleme işlemi için bir IOPMAssertionType tanımlanıyor. */
    IOReturn success = IOPMAssertionCreateWithName(kIOPMAssertionTypeNoDisplaySleep,
                                                    /* Uyku önleme seviyesi tanımlanıyor. */
                                                    kIOPMAssertionLevelOn,
                                                    /* Aktivitenin nedeni belirtiliyor. */
                                                    reasonForActivity,
                                                    /* Tanımlanan ID IOPMAssertionCreateWithName fonksiyonuna atanıyor. */
                                                    &assertionID);

    (void)av;
    if(ac == 1)
    {
        if(success == kIOReturnSuccess)
        {
            printf("%sSince no specific parameter is given to sleepwipe, it will prevent the computer from sleeping until the program is terminated.%s\n", RED, RESET);
            CFRunLoopRun();
            success = IOPMAssertionRelease(assertionID);
        }
    }
    else if(ac == 2 || ac == 3)
    {
        // Parse action
        cmd_parser(av);
    }
    else
    {
        // Unusable format and printing help area
        print_usage();
    }
    return success;
}