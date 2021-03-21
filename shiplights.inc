#declare L3Emission = 4.0;
global_settings {
	ambient_light 0
	radiosity { }
}

#ifndef (L3FinishTransparentGlow)
#macro L3FinishTransparentGlow(r,g,b,l)
finish {
	ambient 0
	diffuse 0
	emission L3Emission*l
	#if (L3Quality >= 2)
		phong 0.5
		phong_size 40
		reflection 0.2
	#end
}
#end
#end

#ifndef (L3TextureTransparentGlowRGBA)
#macro L3TextureTransparentGlowRGBA(r,g,b,a,l)
// Alpha -> Filter: 255 -> 1.00, 128 -> 0.85, 0 -> 0
#local f = (a >= 128 ? 0.85 + (a-128) * 0.15 / (255-128) : a * 0.85 / 255);
texture {
	pigment { rgb <r/255,g/255,b/255> #if (L3Quality > 1) filter f #end }
	L3FinishTransparentGlow(r,g,b,l)
	#if (L3Bumps & (L3Quality > 1)) normal { L3NormalBumps } #end
}
#end
#end

//// Color 34 Trans_Green (from ldconfig.ldr)
#ifndef (L3Texture34)
#declare L3Texture34 = L3TextureTransparentGlowRGBA(35,120,65,128,0.3)
#end

//// Color 36 Trans_Red (from ldconfig.ldr)
#ifndef (L3Texture36)
#declare L3Texture36 = L3TextureTransparentGlowRGBA(201,26,9,128,0.3)
#end

//// Color 39 Trans_Very_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture39)
#declare L3Texture39 = L3TextureTransparentGlowRGBA(193,223,240,128,2)
#end

//// Color 33 Trans_Dark_Blue (from ldconfig.ldr)
#ifndef (L3Texture33)
#declare L3Texture33 = L3TextureTransparentGlowRGBA(0,32,160,128,1)
#end

//// Color 79 Milky_White (from ldconfig.ldr)
#ifndef (L3Texture79)
#declare L3Texture79 = L3TextureTransparentGlowRGBA(238,238,238,240,1)
#end

//// Color 341 Glitter_Trans_Orange (from ldconfig.ldr)
#ifndef (L3Texture341)
#declare L3Texture341 = L3TextureTransparentGlowRGBA(240,143,28,128,0.5)
#end

//// Color 43 Trans_Light_Blue (from ldconfig.ldr)
#ifndef (L3Texture43)
#declare L3Texture43 = L3TextureTransparentGlowRGBA(174,233,239,128,2)
#end
