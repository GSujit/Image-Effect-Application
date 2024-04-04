package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.SepiaInterface.applySepia;

public class SepiaEffect implements PhotoEffect {

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Sepia","-");

        image = applySepia(image);

        return image;
    }

}
