#include "ButtonModuleReader.h"
#include "ButtonModule.h"

using namespace cocos2d;

static ButtonModuleReader* _instanceToolBarReader = nullptr;

ButtonModuleReader* ButtonModuleReader::getInstance()
{
	if (!_instanceToolBarReader)
	{
		_instanceToolBarReader = new ButtonModuleReader();
	}
	return _instanceToolBarReader;
}

void ButtonModuleReader::purge()
{
	CC_SAFE_DELETE(_instanceToolBarReader);
}

Node* ButtonModuleReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	ButtonModule* node = ButtonModule::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}