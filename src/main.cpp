#include <Geode/modify/FLAlertLayer.hpp>

using namespace geode::prelude;

class $modify(MyFLAlertLayer, FLAlertLayer) {
	static void onModify(auto& self) {
		(void) self.setHookPriority("FLAlertLayer::show", -3999);
	}
	void show() {
		const auto pl = PlayLayer::get();
		if (pl && pl->getParent() && pl->getParent()->getChildByType<PauseLayer>(0) && Mod::get()->getSettingValue<bool>("enabled") && !pl->m_isPaused) return this->removeMeAndCleanup();
		FLAlertLayer::show();
	}
};