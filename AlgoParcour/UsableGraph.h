#ifndef USABLEGRAPH_H_INCLUDED
#define USABLEGRAPH_H_INCLUDED

#include "PreGraph.h"
#include "ModuleNode.h"

class UsableGraph
{
    public:
        UsableGraph(PreGraph* preGraph, int length, int maxWidth, const Module& asked
                    //, int authorizedDifference, int negligibleDifference
                    );
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
        int getLength() const {return m_length;}
        int getMaxWidth() const {return m_maxWidth;}
        unsigned int getWidth() const;
        //int getNumberOfPaths() const {return m_numberOfPaths;}
        const Module& askedTotal() const {return m_asked;}
        /*const Module& averageTotal() const {return m_average;}
        const Module& maxTotal() const {return m_max;}
        const Module& minTotal() const {return m_min;}
        int getAuthorizedDifference() const {return m_authorizedDifference;}
        int getNegligibleDifference() const {return m_negligibleDifference;}
        int getMaxDifference() const {return m_maxDifference;}
        int getAverageDifference() const {return m_averageDifference;}*/

    protected:
    private:
        std::vector<std::list<ModuleNode*>>* m_nodes;

        ModuleNode* m_currentNode;

        int m_length, m_maxWidth;
        //int m_width;
        //int m_numberOfPaths;

        const Module m_asked;
        //const Module m_average;
        //const Module m_min;
        //const Module m_max;

        //int m_authorizedDifference, m_negligibleDifference, m_maxDifference, m_averageDifference;

        std::string m_errors;
};

#endif // USABLEGRAPH_H_INCLUDED
