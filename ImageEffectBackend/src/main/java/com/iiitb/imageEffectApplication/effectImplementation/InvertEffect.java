package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.InvertInterface.applyInvert;

public class InvertEffect implements PhotoEffect {

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Invert","-");

        image = applyInvert(image);

        return image;
    }

}
