#include "lightingnight.hpp"

#include <osg/LightSource>

CSVRender::LightingNight::LightingNight() {}

void CSVRender::LightingNight::activate (osg::Group* rootNode)
{
    mRootNode = rootNode;

    mLightSource = new osg::LightSource;

    osg::ref_ptr<osg::Light> light (new osg::Light);
    light->setDirection(osg::Vec3f(0.f, 0.f, -1.f));
    light->setAmbient(osg::Vec4f(0.f, 0.f, 0.f, 1.f));
    light->setDiffuse(osg::Vec4f(0.2f, 0.2f, 0.2f, 1.f));
    light->setSpecular(osg::Vec4f(0.f, 0.f, 0.f, 0.f));
    light->setConstantAttenuation(1.f);

    mLightSource->setLight(light);

    mRootNode->addChild(mLightSource);
}

void CSVRender::LightingNight::deactivate()
{
    if (mRootNode && mLightSource.get())
        mRootNode->removeChild(mLightSource);
}

osg::Vec4f CSVRender::LightingNight::getAmbientColour(osg::Vec4f *defaultAmbient)
{
    if (defaultAmbient)
        return *defaultAmbient;
    else
        return osg::Vec4f(0.2f, 0.2f, 0.2f, 1.f);
}
