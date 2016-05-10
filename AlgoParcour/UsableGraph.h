#ifndef USABLEGRAPH_H_INCLUDED
#define USABLEGRAPH_H_INCLUDED

#include "PreGraph.h"
#include "ModuleNode.h"

class UsableGraph
{
    public:
        UsableGraph(PreGraph* preGraph, unsigned int length, unsigned int maxWidth,
                    const Module& asked, const Module& authorizedDifference);
        UsableGraph(const UsableGraph& other);
        ~UsableGraph();
        UsableGraph& operator=(const UsableGraph& other);

        std::vector<std::list<ModuleNode*>>* getNodes() const {return m_nodes;}
        void display() const;

        const ModuleNode* getCurrentNode() const {return m_currentNode;}
        void setCurrentNode(ModuleNode* moduleNode) {m_currentNode = moduleNode;}
        bool moveForward(unsigned int k);
        bool moveForwardTo(ModuleNode* mn);
        bool moveBackward(unsigned int k);
        bool moveBackwardTo(ModuleNode* mn);

        bool isValid() const {return 0 == m_errors.compare("");}

        std::string getErrors() const {return m_errors;}

        unsigned int getLength() const {return m_length;}
        unsigned int getMaxWidth() const {return m_maxWidth;}
        unsigned int getWidth() const;
        unsigned int getNumberOfPaths() const {return m_numberOfPaths;}

        const Module& askedTotal() const {return m_asked;}
        const Module& maxTotal() const {return m_max;}
        const Module& minTotal() const {return m_min;}
        const Module& getAuthorizedDifference() const {return m_authorizedDifferences;}
        unsigned int getMaxDifference() const {return m_maxDifference;}
        float getAverageDifference() const {return m_averageDifference;}

    protected:
    private:
        std::vector<std::list<ModuleNode*>>* m_nodes;

        ModuleNode* m_currentNode;

        unsigned int m_length, m_maxWidth;
        unsigned int m_numberOfPaths;

        const Module m_asked;
        const Module m_authorizedDifferences;
        Module m_min;
        Module m_max;

        unsigned int m_maxDifference;
        float m_averageDifference;

        std::string m_errors;
};

#endif // USABLEGRAPH_H_INCLUDED
