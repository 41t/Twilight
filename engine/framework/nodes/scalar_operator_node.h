#pragma once
#include "node.h"

class ScalarOperatorNode : public Node<ScalarOperatorNode>
{
public:
	void InitializeSlots() override;
	void Update(double deltaSeconds) override;

	JSON ToJson() const override;
	void FromJson(const JSON& json) override;

	void DrawWidget() override;

private:
	static const std::vector<std::string> operationNames;
	uint32_t operationIndex = 0;
};