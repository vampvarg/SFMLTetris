#pragma once
#include "AICommon.h"
#include "Component.h"

#define NUM_LOOKAHEAD (2)
#define AI_UPDATE_RATE_SECONDS (0.0f)

class AIHeuristic;
class AIDebugHeuristic;
class AIEvaluatorComponent : public Component
{
public:
	AIEvaluatorComponent(Tetris* owner);
	virtual ~AIEvaluatorComponent();

	bool CanFindMove() { return m_timeSinceLastUpdate > AI_UPDATE_RATE_SECONDS; }
	DesiredMoveSet GetBestMove() { return m_bestMoves[0]; }			
	float m_timeSinceLastUpdate;
	std::vector<AIHeuristic*> m_heuristics;
	std::vector<AIDebugHeuristic> m_debugHeuristics;
	DesiredMoveSet m_bestMoves[NUM_LOOKAHEAD];
};
