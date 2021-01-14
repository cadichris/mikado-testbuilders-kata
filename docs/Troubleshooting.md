# Troubleshooting

## I am getting C++ compilation errors 

Most probably this is because there is a difference between your and our C++ compiler 
(version, vendor, etc).  

Check the [CPP Build Manual](../cpp/BUILD_MANUAL.md) to learn more about the
tools and compiler versions we used in this project

## I cannot get the googltest dependency in Visual Studio

If you are behind a proxy, you might need to configure your NuGet proxy. Here
are some links that helped me:

* Stackoverflow ["NuGet behind a proxy"](https://stackoverflow.com/questions/9232160/nuget-behind-a-proxy)
* [NuGet config reference](https://docs.microsoft.com/en-us/nuget/reference/nuget-config-file)
* [NuGet proxy settings](http://skolima.blogspot.com/2012/07/nuget-proxy-settings.html)

(Alternatively, you can also connect without a proxy to download the 
dependency, it should continue to build when you get back behind the proxy)