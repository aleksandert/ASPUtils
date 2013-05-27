<%@ language="vbscript" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASPUtilsTest - Cache</title>
    <style type="text/css">
        #stopwatch {border: 1px solid black;padding:0px}
        #stopwatch td {padding: 5px;}
    </style>
    <meta http-equiv="refresh" content="2" />
</head>
<body>

<% 
    Response.Write(Request.Form("action"))

    If Request.Form("action") = "delete" then
    
        Cache.RemoveAll()

        Response.End

    end if

    Set sw = GetObject("script:" & Server.MapPath("scripts/StopWatch.wsc"))

    Dim count : count = 10000

    Randomize
           
    'Adding items to cache
   
    sw.Split("Cache - Set " & count & " items.")

    for i = 1 to count

        key = cstr(i)

        if i mod 3 = 0 then

            Cache.SetAbsolute key, i, DateAdd("s", clng(Rnd()*10), Now())
        
        elseif i mod 3 = 1 then
        
            'Cache.SetSliding key, i, clng(Rnd()*10)

        else

        '    Cache(key) = i

        end if

        'Cache(key) = i

    next

    sw.Split("Cache - Remove up to " & count / 10 & " keys")

    'Removing items from cache

    for i = 1 to count / 10

        key = cstr(clng(Rnd() * count))

         if Cache.Exists(key) then
            
            Cache.Remove(key)

        end if

    next
    
    'iterating cache items
        
    sw.Split("Cache - ForEach " & Cache.Count & " keys")
    
    i = 0
    size = 0
    expires = DateSerial(1900, 1, 1)
    
    response.Write(expires)

    for each key in Cache.Keys
    
        i = i + 1

        value = Cache(key)

        'item size in bytes
        size = size + Cache.GetSize(key)
        
        'absolute expire 
        ex = Cache.Expires(key)

        if not IsEmpty(ex) then
            expires = ex
        end if

    next

    sw.Split(i & " keys enumerated. " & size & " bytes, expires " & expires)


    sw.Split("Cache - End")

 %>

     Rendered at <%=Now() %><br />
     Cached Items <%=Cache.Count %>

     <%sw.Render() %>

     <form method="post" action="Cache.asp">
        <button type="submit" name="action" value="delete">Delete</button>
     </form>

</body>
</html>
