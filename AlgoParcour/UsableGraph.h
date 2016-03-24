#ifndef USABLEGRAPH_H_INCLUDED
#define USABLEGRAPH_H_INCLUDED

#include <list>

#include "PreGraph.h"
#include "ModuleNode.h"

class UsableGraph
{
    public:
        UsableGraph(PreGraph* preGraph, int length, int maxWidth,
                    int askedReading, int askedWriting, int askedMaths, int askedFun
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
        int getAskedReading() const {return m_askedReading;}
        int getAskedWriting() const {return m_askedWriting;}
        int getAskedMaths() const {return m_askedMaths;}
        int getAskedFun() const {return m_askedFun;}
        /*int getAverageReading() const {return m_averageReading;}
        int getAverageWriting() const {return m_averageWriting;}
        int getAverageMaths() const {return m_averageMaths;}
        int getAverageFun() const {return m_averageFun;}
        int getMaxReading() const {return m_maxReading;}
        int getMaxWriting() const {return m_maxWriting;}
        int getMaxMaths() const {return m_maxMaths;}
        int getMaxFun() const {return m_maxFun;}
        int getMinReading() const {return m_minReading;}
        int getMinWriting() const {return m_minWriting;}
        int getMinMaths() const {return m_minMaths;}
        int getMinFun() const {return m_minFun;}
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

        int m_askedReading, m_askedWriting, m_askedMaths, m_askedFun;
        //int m_averageReading, m_averageWriting, m_averageMaths, m_averageFun;
        //int m_minReading, m_minWriting, m_minMaths, m_minFun;
        //int m_maxReading, m_maxWriting, m_maxMaths, m_maxFun;

        //int m_authorizedDifference, m_negligibleDifference, m_maxDifference, m_averageDifference;

        std::string m_errors;
};

#endif // USABLEGRAPH_H_INCLUDED
