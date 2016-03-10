#include "ToolBarReader.h"
#include "ToolBar.h"

using namespace cocos2d;

static ToolBarReader* _instanceToolBarReader = nullptr;

ToolBarReader* ToolBarReader::getInstance()
{
	if (!_instanceToolBarReader)
	{
		_instanceToolBarReader = new ToolBarReader();
	}
	return _instanceToolBarReader;
}

void ToolBarReader::purge()
{
	CC_SAFE_DELETE(_instanceToolBarReader);
}

Node* ToolBarReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	ToolBar* node = ToolBar::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}