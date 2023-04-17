#pragma once

#include "SearchMethod.h"

class AStarSearch : public SearchMethod
{
private:
	const Puzzle* m_Puzzle;
public:
	AStarSearch();

	std::vector<Direction> TracePath(const Node& leaf);
	std::vector<Direction> Solve(const Puzzle& puzzle) override;

	inline int GetIterationCount() const { return m_Iterations; }
	inline static String GetStaticName() { return "A* Search"; }
	inline static String GetCode() { return "AS"; }
	inline String GetName() override { return GetStaticName(); }
private:
	Node* FindBestNode(const std::vector<Node*>& set, int* index = nullptr);
	short CalculateHeuristic(byte* state, byte* goalState, byte width, byte height);
};