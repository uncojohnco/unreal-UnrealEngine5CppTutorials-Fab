// Fab by Johnny Cochrane


#include "FabHUD.h"
#include "AttributesWidget.h"


void AFabHUD::Init()
{
	AttributeWidget = CreateWidget<UAttributesWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributeWidget->BindToAttributes();
	AttributeWidget->AddToViewport();
}
