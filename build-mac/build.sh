#!/bin/bash

#  Automatic build script for libetpan 
#  for iOS and iOSSimulator
#
#  Created by Felix Schulze on 19.02.12.
#  Copyright 2012 Felix Schulze. All rights reserved.
###########################################################################
#
SDKVERSION="5.0"
#
###########################################################################
#
# Don't change anything here
DEVICESDK="iphoneos${SDKVERSION}"
SIMSDK="iphonesimulator${SDKVERSION}"

echo "Building libOAuth for iPhoneSimulator and iPhoneOS ${SDKVERSION}"
# Clean the targets
if ! xcodebuild -project "libetpan.xcodeproj" -target "static libetpan" -configuration "Release" -sdk "$DEVICESDK" clean ; then
	exit 1
fi
if ! xcodebuild -project "libetpan.xcodeproj" -target "static libetpan" -configuration "Release" -sdk "$SIMSDK" clean ; then
	exit 1
fi

# Build the targets
if ! xcodebuild -project "libetpan.xcodeproj" -target "static libetpan" -configuration "Release" -sdk "$SIMSDK" -arch "i386" ; then
	exit 1
fi
if ! xcodebuild -project "libetpan.xcodeproj" -target "static libetpan" -configuration "Release" -sdk "$DEVICESDK" -arch "armv6 armv7" ; then
	exit 1
fi

echo "Build library..."
lipo "build/Release-iphoneos/libetpan.a" "build/Release-iphonesimulator/libetpan.a" -create -output "libetpan.a"
echo "Building done."