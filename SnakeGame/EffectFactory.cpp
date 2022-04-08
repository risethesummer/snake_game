#include "EffectFactory.h"

void deadEffect(const Snake& snake){
  print(snake,'YOU ARE DEAD', RED_RED);
  PlaySound(TEXT("deathSoundEffect.wav"), NULL, SND_SYNC); 
}

void passGateEffect(const Snake& snake){
  PlaySound(TEXT("passEffect.wav"), NULL, SND_SYNC); 
}


