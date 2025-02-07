#include <Geode/modify/FLAlertLayer.hpp>

using namespace geode::prelude;

class $modify(MyFLAlertLayer, FLAlertLayer) {
	void show() {
		const auto pl = PlayLayer::get();
		if (!pl) return FLAlertLayer::show();
		if (!pl->getParent()) return FLAlertLayer::show();
		if (!pl->getParent()->getChildByType<PauseLayer>(0)) return FLAlertLayer::show();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return FLAlertLayer::show();
		if (pl->m_isPaused) return FLAlertLayer::show();
		this->removeMeAndCleanup();
	}
};