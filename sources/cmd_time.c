#include "../includes/sleepwipe.h"

static void timer_callback(CFRunLoopTimerRef timer, void *info) {
    (void)info;
    (void)timer;
    CFRunLoopStop(CFRunLoopGetCurrent());
}

int t_sleep(t_list cmd)
{
    CFRunLoopTimerContext context = {0, NULL, NULL, NULL, NULL};
    CFRunLoopTimerRef timer = CFRunLoopTimerCreate(NULL, CFAbsoluteTimeGetCurrent() + cmd.cmd_act_input, 0, 0, 0, timer_callback, &context);
    CFRunLoopAddTimer(CFRunLoopGetCurrent(), timer, kCFRunLoopCommonModes);
    CFRunLoopRun();
    CFRunLoopRemoveTimer(CFRunLoopGetCurrent(), timer, kCFRunLoopCommonModes);
    CFRelease(timer);
    return -1;
}