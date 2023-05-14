#include "../includes/sleepwipe.h"

int main(int ac, char **av)
{
    IOPMAssertionID assertionID;
    CFStringRef reasonForActivity= CFSTR("Prevent system sleep");
    IOReturn success = IOPMAssertionCreateWithName(kIOPMAssertionTypeNoDisplaySleep,
                                                    kIOPMAssertionLevelOn,
                                                    reasonForActivity,
                                                    &assertionID);
    if(ac == 1)
    {
        if(success == kIOReturnSuccess)
        {
            printf("%sSince no specific parameter is given to sleepwipe, it will prevent the computer from sleeping until the program is terminated.%s\n", BOLDRED, RESET);
            CFRunLoopRun();
            success = IOPMAssertionRelease(assertionID);
        }
    }
    else if(ac == 4)
    {
        if(success == kIOReturnSuccess)
        {
            t_list cmd_lst;
            cmd_parser(av + 1, &cmd_lst);
        }
    }
    else
        print_usage();
    return success;
}