#pragma once
#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class ButtonModuleReader : public cocostudio::NodeReader
{
public:
	static ButtonModuleReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

