#pragma once
#include "DrawDebugHelpers.h"

// Debug messages
#define DBG_PRINT_ONSCREEN(DebugMessage, ...) { GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Purple, FString::Printf(TEXT(DebugMessage), __VA_ARGS__)); }

// Debug draw helpers
#define DBG_SPHERE(Center) if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20.f, 16, FColor::Blue, true);
#define DBG_SPHERE_TICK(Center) if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20.f, 16, FColor::Green, false);
#define DBG_LINE(LineStart, LineEnd) if (GetWorld()) DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Blue, true);
#define DBG_LINE_TICK(LineStart, LineEnd) if (GetWorld()) DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Green, false);
