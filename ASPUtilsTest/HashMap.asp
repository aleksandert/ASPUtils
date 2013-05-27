<%@ language="vbscript" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASPUtilsTest - HashMap</title>
    <style type="text/css">
        #stopwatch {border: 1px solid black;padding:0px}
        #stopwatch td {padding: 5px;}
    </style>
    <meta http-equiv="refresh" content="1" />
</head>
<body>

<% 
    Set sw = GetObject("script:" & Server.MapPath("scripts/StopWatch.wsc"))

    Dim count : count = 50000

    Randomize

    'HashMap

    Set HashMap = CreateObject("ASPUtils.HashMap")

    'Set HashMap = CreateObject("Scripting.Dictionary")
   
    sw.Split("HashMap - Set " & count & " items.")

    for i = 1 to count

        key = cstr(i)

        HashMap(key) = i

    next

    sw.Split("HashMap - Remove up to " & count / 10 & " keys")

    'Removing

    for i = 1 to count / 10

        key = cstr(clng(Rnd() * count))

        if HashMap.Exists(key) then
            
            HashMap.Remove(key)

        end if

    next

    sw.Split("HashMap - ForEach " & HashMap.Count & " keys")
    
    i = 0
    size = 0
        
    response.Write(expires)

    for each key in HashMap.Keys
    
        i = i + 1

        value = HashMap(key)
                
    next

    sw.Split(i & " keys enumerated. " & size & " bytes, expires " & expires)


    sw.Split("HashMap - End")

    Set HashMap = nothing
    
    
%>
    
     Rendered at <%=Now() %><br />

     <%sw.Render() %>
</body>
</html>
