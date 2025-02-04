<script setup lang="ts">
import { RouterLink, RouterView } from 'vue-router'
import HelloWorld from './components/HelloWorld.vue'
import { ref, onMounted } from 'vue';

const cookieValue = ref(''); // Reactive variable to store the cookie value
const responseData = ref(null); // Reactive variable to store the response data

function getParentBaseUrl() {
  try {
    const parentUrl = new URL(window.parent.location.href); // Parse the parent URL
    const pathnameParts = parentUrl.pathname.split('/'); // Split the pathname into parts
    const basePath = pathnameParts.slice(0, 2).join('/'); // Keep only the first three parts
    const baseUrl = `${parentUrl.origin}${basePath}/`; // Combine origin and base path
    console.log('Base URL:', baseUrl);
    return baseUrl; // Return the base URL
  } catch (error) {
    console.error('Unable to extract base URL from parent:', error);
    return null;
  }
}

// Method to retrieve URL parameters from parent window
function fetchParentUrlParams() {
  try {
    const parentSearch = window.parent.location.search; // Access parent URL's query string
    console.log('Raw Parent Search:', parentSearch);

    // Remove the initial "?" and look for "contact_id"
    const rawQuery = parentSearch.slice(1); // Remove the leading '?'
    const match = rawQuery.match(/contact_id=([^&]+)/); // Regex to find "contact_id"
    const contactId = match ? match[1] : null; // Extract the value or set null
    console.log('Extracted Contact ID:', contactId);
    return contactId; // Return the value if needed
  } catch (error) {
    console.error('Unable to access parent URL parameters:', error);
    return null;
  }
}

// Method to retrieve a specific cookie value
function getCookieValue(cookieName: string) {
  const match = document.cookie.match(new RegExp('(^| )' + cookieName + '=([^;]+)'));
  return match ? match[2] : null;
}

// Method to make an HTTP request using the cookie value
async function makeHttpRequest() {
  const value = getCookieValue("XSRF-TOKEN");
  cookieValue.value = value || 'Cookie not found';

  if (value) {
    try {
      const contactId = fetchParentUrlParams();
      const baseUrl = getParentBaseUrl();
      const response = await fetch(`${baseUrl}api/v1/Contact/${contactId}`, {
        method: 'GET', // Change to 'POST', 'PUT', etc., as needed
        headers: {
          'Accept': 'application/json',
          'X-XSRF-TOKEN': `${value}`, // Use cookie value in a header
        },
      });
      responseData.value = await response.json();
      console.log('Response Data:', responseData.value);
    } catch (error) {
      console.error('Error making HTTP request:', error);
    }
  } else {
    console.log('No cookie value found, skipping HTTP request.');
  }
}

// Fetch the cookie value when the app is mounted
onMounted(() => {
  makeHttpRequest(); 
});
</script>

<template>
  <header>
    <img alt="Vue logo" class="logo" src="@/assets/logo.svg" width="125" height="125" />

    <div class="wrapper">
      <HelloWorld msg="You did it!" />

      <nav>
        <RouterLink to="/">Home</RouterLink>
        <RouterLink to="/about">About</RouterLink>
      </nav>

     <!-- Display raw JSON response -->
      <p>This is some data fetched with the XSRF-TOKEN fetched from the cookies</p>
      <pre v-if="responseData">{{ responseData }}</pre>

    </div>
  </header>

  <RouterView />
</template>

<style scoped>
header {
  line-height: 1.5;
  max-height: 100vh;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

nav {
  width: 100%;
  font-size: 12px;
  text-align: center;
  margin-top: 2rem;
}

nav a.router-link-exact-active {
  color: var(--color-text);
}

nav a.router-link-exact-active:hover {
  background-color: transparent;
}

nav a {
  display: inline-block;
  padding: 0 1rem;
  border-left: 1px solid var(--color-border);
}

nav a:first-of-type {
  border: 0;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }

  nav {
    text-align: left;
    margin-left: -1rem;
    font-size: 1rem;

    padding: 1rem 0;
    margin-top: 1rem;
  }
}
</style>
