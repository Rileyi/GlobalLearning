#ifndef MODULENODE_H_INCLUDED
#define MODULENODE_H_INCLUDED

#include "ModuleGE.h"

class ModuleNode : public Module //, public cocos2d::Node
{
    public:
        ModuleNode(const ModuleGE* m);
        ~ModuleNode();
        ModuleNode(const ModuleNode& other);
        ModuleNode& operator=(const ModuleNode& other);

        void display() const;

        std::vector<ModuleNode*>* getPrevious() const { return m_previous; }
        std::vector<ModuleNode*>* getNext() const { return m_next; }

        void addNext(ModuleNode* moduleNode);
        void addNext(std::vector<ModuleNode*>& moduleNodes);

        void addPrevious(ModuleNode* moduleNode);
        void addPrevious(std::vector<ModuleNode*>& moduleNodes);

        bool calculatePathData(const Module& asked, const Module& authorizedDifference,
                               Module* totalMin, Module* totalMax,
                               unsigned int* numberOfPaths, unsigned int* maxDifference,
                               float* averageDifference )
                               const;

        void recursiveDelete();

    protected:

    private:
        std::vector<ModuleNode*>* m_previous;
        std::vector<ModuleNode*>* m_next;
};

#endif // MODULENODE_H_INCLUDED
